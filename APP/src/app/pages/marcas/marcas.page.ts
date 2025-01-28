import { CommonModule } from '@angular/common';
import { Component, OnInit } from '@angular/core';
import { RouterLink } from '@angular/router';
import { AlertController, IonicModule, LoadingController, ToastController } from '@ionic/angular';
import { Marca } from 'src/app/model/marca';
import { MarcaService } from 'src/app/services/marca.service';

@Component({
  selector: 'app-marcas',
  templateUrl: './marcas.page.html',
  styleUrls: ['./marcas.page.scss'],
  imports: [IonicModule, CommonModule, RouterLink]
})
export class MarcasPage implements OnInit {
  marcas: Marca[];

  constructor(private marcaService: MarcaService, private toastController: ToastController,
    private alertController: AlertController, private loadingController: LoadingController) {
    this.marcas = [];
  }

  ngOnInit() {
  }

  async ionViewWillEnter() {
    this.loadList();
  }

  async loadList() {
    this.showLoader();

    await this.marcaService.getAll()
      .then((json) => {
        this.marcas = <Marca[]>(json);
      });

    this.closeLoader();
  }

  showLoader() {
    this.loadingController.create({
      message: 'Carregando...'
    }).then((res) => {
      res.present();
    })
  }

  closeLoader() {
    setTimeout(() => {
      this.loadingController.dismiss().then(() => {
      }).catch((erro) => {
        console.log('Erro: ', erro)
      });
    }, 500);
  }

  async showMessage(texto: string) {
    const toast = await this.toastController.create({
      message: texto,
      duration: 1500
    })
    toast.present();
  }

  async delete(marca: Marca) {
    const alert = await this.alertController.create({
      header: 'Você tem certeza que quer excluir essa marca?',
      message: marca.nome,
      buttons: [
        {
          text: 'Cancelar'
        }, {
          text: 'Sim',
          cssClass: 'danger',
          handler: () => {
            this.marcaService.delete(marca.idMarca).then(() => {
              this.loadList();
              this.showMessage('Marca excluída com sucesso!');
            }).catch(() => {
              this.showMessage('Erro ao excluir a marca.');
            });
          }
        }
      ]
    })
    await alert.present();
  }
}
