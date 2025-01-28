import { CommonModule } from '@angular/common';
import { Component, OnInit } from '@angular/core';
import { RouterLink } from '@angular/router';
import { AlertController, IonicModule, LoadingController, ToastController } from '@ionic/angular';
import { Cliente } from 'src/app/model/cliente';
import { ClienteService } from 'src/app/services/cliente.service';

@Component({
  selector: 'app-clientes',
  templateUrl: './clientes.page.html',
  styleUrls: ['./clientes.page.scss'],
  imports: [IonicModule, CommonModule, RouterLink]
})
export class ClientesPage implements OnInit {

  clientes: Cliente[];

  constructor(private clienteService: ClienteService, private toastController: ToastController,
    private alertController: AlertController, private loadingController: LoadingController) {
    this.clientes = [];
  }

  ngOnInit() {
  }

  async ionViewWillEnter() {
    this.loadList();
  }

  async loadList() {
    this.showLoader();

    await this.clienteService.getAll()
      .then((json) => {
        this.clientes = <Cliente[]>(json);
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

  async delete(cliente: Cliente) {
    const alert = await this.alertController.create({
      header: 'Você tem certeza que quer excluir esse cliente?',
      message: cliente.nome,
      buttons: [
        {
          text: 'Cancelar'
        }, {
          text: 'Sim',
          cssClass: 'danger',
          handler: () => {
            this.clienteService.delete(cliente.idPessoa).then(() => {
              this.loadList();
              this.showMessage('Cliente excluído com sucesso!');
            }).catch(() => {
              this.showMessage('Erro ao excluir o cliente.');
            });
          }
        }
      ]
    })
    await alert.present();
  }
}
