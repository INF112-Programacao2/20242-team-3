import { CommonModule } from '@angular/common';
import { Component, OnInit } from '@angular/core';
import { RouterLink } from '@angular/router';
import { AlertController, IonicModule, LoadingController, ToastController } from '@ionic/angular';
import { Produto } from 'src/app/model/produto';
import { BermudaService } from 'src/app/services/bermuda.service';
import { FaixaService } from 'src/app/services/faixa.service';
import { KimonoService } from 'src/app/services/kimono.service';
import { RashGuardService } from 'src/app/services/rash-guard.service';

@Component({
  selector: 'app-produtos',
  templateUrl: './produtos.page.html',
  styleUrls: ['./produtos.page.scss'],
  imports: [IonicModule, CommonModule, RouterLink]
})
export class ProdutosPage implements OnInit {

  produtos: Produto[];

  constructor(private kimonoService: KimonoService, private bermudaService: BermudaService, private faixaService: FaixaService, private rashGuardService : RashGuardService, private toastController: ToastController,
    private alertController: AlertController, private loadingController: LoadingController) {
    this.produtos = [];
  }

  ngOnInit() {
  }

  async ionViewWillEnter() {
    this.loadList();
  }

  async loadList() {
    this.showLoader();

    const kimonos = await this.kimonoService.getAll();
    console.log(kimonos);

    const bermudas = await this.bermudaService.getAll();
    console.log(bermudas);

    const faixas = await this.faixaService.getAll();
    console.log(faixas);

    const rash_guards = await this.rashGuardService.getAll();
    console.log(rash_guards);

    // Combinando os arrays de produtos
    this.produtos = [...(kimonos as Produto[]), ...(bermudas as Produto[]), ...(faixas as Produto[]), ...(rash_guards as Produto[])];

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

  async delete(produto: Produto) {
    const alert = await this.alertController.create({
      header: 'Você tem certeza que quer excluir esse Produto?',
      message: produto.SKU,
      buttons: [
        {
          text: 'Cancelar'
        }, {
          text: 'Sim',
          cssClass: 'danger',
          handler: () => {
            this.kimonoService.delete(produto.idProduto).then(() => {
              this.loadList();
              this.showMessage('Produto excluído com sucesso!');
            }).catch(() => {
              this.showMessage('Erro ao excluir o Produto.');
            });
          }
        }
      ]
    })
    await alert.present();
  }
}

