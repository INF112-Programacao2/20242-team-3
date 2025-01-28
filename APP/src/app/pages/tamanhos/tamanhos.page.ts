import { CommonModule } from '@angular/common';
import { Component, OnInit } from '@angular/core';
import { RouterLink } from '@angular/router';
import { AlertController, IonicModule, LoadingController, ToastController } from '@ionic/angular';
import { Tamanho } from 'src/app/model/tamanho';
import { TamanhoService } from 'src/app/services/tamanho.service';

@Component({
  selector: 'app-tamanhos',
  templateUrl: './tamanhos.page.html',
  styleUrls: ['./tamanhos.page.scss'],
  imports: [IonicModule, CommonModule, RouterLink]
})
export class TamanhosPage implements OnInit {

  tamanhos: Tamanho[];

  constructor(private tamanhoService: TamanhoService, private toastController: ToastController,
    private alertController: AlertController, private loadingController: LoadingController) {
    this.tamanhos = [];
  }

  ngOnInit() {
  }

  async ionViewWillEnter() {
    this.loadList();
  }

  async loadList() {
    this.showLoader();

    await this.tamanhoService.getAll()
      .then((json) => {
        this.tamanhos = <Tamanho[]>(json);
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

  async delete(tamanho: Tamanho) {
    const alert = await this.alertController.create({
      header: 'Você tem certeza que quer excluir esse tamanho?',
      message: tamanho.nome,
      buttons: [
        {
          text: 'Cancelar'
        }, {
          text: 'Sim',
          cssClass: 'danger',
          handler: () => {
            this.tamanhoService.delete(tamanho.idTamanho).then(() => {
              this.loadList();
              this.showMessage('Tamanho excluído com sucesso!');
            }).catch(() => {
              this.showMessage('Erro ao excluir o tamanho.');
            });
          }
        }
      ]
    })
    await alert.present();
  }
}
