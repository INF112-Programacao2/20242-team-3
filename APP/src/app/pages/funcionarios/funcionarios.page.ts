import { CommonModule } from '@angular/common';
import { Component, OnInit } from '@angular/core';
import { RouterLink } from '@angular/router';
import { AlertController, IonicModule, LoadingController, ToastController } from '@ionic/angular';
import { Funcionario } from 'src/app/model/funcionario';
import { FuncionarioService } from 'src/app/services/funcionario.service';

@Component({
  selector: 'app-funcionarios',
  templateUrl: './funcionarios.page.html',
  styleUrls: ['./funcionarios.page.scss'],
  imports: [IonicModule, CommonModule, RouterLink]
})
export class FuncionariosPage implements OnInit {

  funcionarios: Funcionario[];

  constructor(private funcionarioService: FuncionarioService, private toastController: ToastController,
    private alertController: AlertController, private loadingController: LoadingController) {
    this.funcionarios = [];
  }

  ngOnInit() {
  }

  async ionViewWillEnter() {
    this.loadList();
  }

  async loadList() {
    this.showLoader();

    await this.funcionarioService.getAll()
      .then((json) => {
        this.funcionarios = <Funcionario[]>(json);
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

  async delete(funcionario: Funcionario) {
    const alert = await this.alertController.create({
      header: 'Você tem certeza que quer excluir esse funcionario?',
      message: funcionario.nome,
      buttons: [
        {
          text: 'Cancelar'
        }, {
          text: 'Sim',
          cssClass: 'danger',
          handler: () => {
            this.funcionarioService.delete(funcionario.idPessoa).then(() => {
              this.loadList();
              this.showMessage('Funcionario excluído com sucesso!');
            }).catch(() => {
              this.showMessage('Erro ao excluir o funcionario.');
            });
          }
        }
      ]
    })
    await alert.present();
  }
}
