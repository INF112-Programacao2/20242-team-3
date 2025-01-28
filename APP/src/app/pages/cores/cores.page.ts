import { CommonModule } from '@angular/common';
import { Component, OnInit } from '@angular/core';
import { RouterLink } from '@angular/router';
import { AlertController, IonicModule, LoadingController, ToastController } from '@ionic/angular';
import { Cor } from 'src/app/model/cor';
import { CorService } from 'src/app/services/cor.service';

@Component({
  selector: 'app-cores',
  templateUrl: './cores.page.html',
  styleUrls: ['./cores.page.scss'],
  imports: [IonicModule, CommonModule, RouterLink]
})
export class CoresPage implements OnInit {
  cores: Cor[];

  constructor(private corService: CorService, private toastController: ToastController,
    private alertController: AlertController, private loadingController: LoadingController) {
    this.cores = [];
  }

  ngOnInit() {
  }

  async ionViewWillEnter() {
    this.loadList();
  }

  async loadList() {
    this.showLoader();

    await this.corService.getAll()
      .then((json) => {
        this.cores = <Cor[]>(json);
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

  async delete(cor: Cor) {
    const alert = await this.alertController.create({
      header: 'Você tem certeza que quer excluir essa cor?',
      message: cor.nome,
      buttons: [
        {
          text: 'Cancelar'
        }, {
          text: 'Sim',
          cssClass: 'danger',
          handler: () => {
            this.corService.delete(cor.idCor).then(() => {
              this.loadList();
              this.showMessage('Cor excluída com sucesso!');
            }).catch(() => {
              this.showMessage('Erro ao excluir a cor.');
            });
          }
        }
      ]
    })
    await alert.present();
  }
}
