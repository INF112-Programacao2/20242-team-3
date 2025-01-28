import { CommonModule } from '@angular/common';
import { Component, OnInit } from '@angular/core';
import { RouterLink } from '@angular/router';
import { AlertController, IonicModule, LoadingController, ToastController } from '@ionic/angular';
import { Modelo } from 'src/app/model/modelo';
import { ModeloService } from 'src/app/services/modelo.service';

@Component({
  selector: 'app-modelos',
  templateUrl: './modelos.page.html',
  styleUrls: ['./modelos.page.scss'],
  imports: [IonicModule, CommonModule, RouterLink]
})
export class ModelosPage implements OnInit {

  modelos: Modelo[];

  constructor(private modeloService: ModeloService, private toastController: ToastController,
    private alertController: AlertController, private loadingController: LoadingController) {
    this.modelos = [];
  }

  ngOnInit() {
  }

  async ionViewWillEnter() {
    this.loadList();
  }

  async loadList() {
    this.showLoader();

    await this.modeloService.getAll()
      .then((json) => {
        this.modelos = <Modelo[]>(json);
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

  async delete(modelo: Modelo) {
    const alert = await this.alertController.create({
      header: 'Você tem certeza que quer excluir esse modelo?',
      message: modelo.nome,
      buttons: [
        {
          text: 'Cancelar'
        }, {
          text: 'Sim',
          cssClass: 'danger',
          handler: () => {
            this.modeloService.delete(modelo.idModelo).then(() => {
              this.loadList();
              this.showMessage('Modelo excluído com sucesso!');
            }).catch(() => {
              this.showMessage('Erro ao excluir o modelo.');
            });
          }
        }
      ]
    })
    await alert.present();
  }
}
