import { CommonModule } from '@angular/common';
import { Component, OnInit } from '@angular/core';
import { FormBuilder, FormGroup, ReactiveFormsModule, Validators } from '@angular/forms';
import { ActivatedRoute } from '@angular/router';
import { IonicModule, LoadingController, NavController, ToastController } from '@ionic/angular';
import { Bermuda } from 'src/app/model/bermuda';
import { Cor } from 'src/app/model/cor';
import { Faixa } from 'src/app/model/faixa';
import { Kimono } from 'src/app/model/kimono';
import { Marca } from 'src/app/model/marca';
import { Modelo } from 'src/app/model/modelo';
import { Produto } from 'src/app/model/produto';
import { Rash_Guard } from 'src/app/model/rash-guard';
import { Tamanho } from 'src/app/model/tamanho';
import { BermudaService } from 'src/app/services/bermuda.service';
import { FaixaService } from 'src/app/services/faixa.service';
import { KimonoService } from 'src/app/services/kimono.service';
import { MarcaService } from 'src/app/services/marca.service';
import { ModeloService } from 'src/app/services/modelo.service';
import { RashGuardService } from 'src/app/services/rash-guard.service';
import { TamanhoService } from 'src/app/services/tamanho.service';
@Component({
  selector: 'app-produto-form',
  templateUrl: './produto-form.page.html',
  styleUrls: ['./produto-form.page.scss'],
  imports: [IonicModule, ReactiveFormsModule, CommonModule]
})
export class ProdutoFormPage implements OnInit {
  marcas: Marca[];
  modelos: Modelo[];
  tamanhos: Tamanho[];
  tipoProduto: string;
  cores: Cor[];
  produto: Produto;
  formGroup: FormGroup;

  constructor(private tamanhoService: TamanhoService, private kimonoService: KimonoService, private bermudaService: BermudaService, private faixaService: FaixaService, private rashGuardService: RashGuardService, private marcaService: MarcaService, private modeloService: ModeloService, private activatedRoute: ActivatedRoute, private formBuilder: FormBuilder,
    private navController: NavController, private toastController: ToastController, private loadingController: LoadingController) {

    this.produto = new Produto();
    this.marcas = [];
    this.modelos = [];
    this.tamanhos = [];
    this.tipoProduto = "";
    this.cores = [];

    this.formGroup = formBuilder.group({
      'idMarca': [this.produto.idMarca, Validators.compose([
        Validators.required,
      ])],
      'idModelo': [this.produto.idModelo, Validators.compose([
        Validators.required,
      ])],
      'SKU': [this.produto.SKU, Validators.compose([
        Validators.required,
      ])],
      'faixaEtaria': [this.produto.faixaEtaria, Validators.compose([
        Validators.required,
      ])],
      'idTamanho': [this.produto.idTamanho, Validators.compose([
        Validators.required,
      ])],
      'sexo': [this.produto.sexo, Validators.compose([
        Validators.required,
      ])],
      'idCor': [this.produto.idCor, Validators.compose([
        Validators.required,
      ])],
    });
  }

  async findTipoProduto(idProduto: number) {
    const servicos = [
      { service: this.bermudaService, tipo: "BERMUDA" },
      { service: this.faixaService, tipo: "FAIXA" },
      { service: this.kimonoService, tipo: "KIMONO" },
      { service: this.rashGuardService, tipo: "RASH_GUARD" },
    ];

    for (const { service, tipo } of servicos) {
      const json = await service.getById(idProduto);
      if (json) { // Valida se o JSON não está vazio
        this.tipoProduto = tipo;
        break; // Para o loop após encontrar o tipo
      }
    }
  }


  async ionViewWillEnter() {
    this.loadList();
  }

  async loadList() {
    this.showLoader();

    await this.marcaService.getAll().then((json) => {
      this.marcas = <Marca[]>(json);
    });

    await this.modeloService.getAll().then((json) => {
      this.modelos = <Modelo[]>(json);
    });

    await this.tamanhoService.getAllByTipoProduto("BERMUDA").then((json) => {
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

  private async loadProdutoIfExists() {
    const idProduto = this.activatedRoute.snapshot.params['idProduto'];
    if (idProduto != null) {
      await this.findTipoProduto(idProduto);

      const servicos = {
        BERMUDA: this.bermudaService,
        FAIXA: this.faixaService,
        KIMONO: this.kimonoService,
        RASH_GUARD: this.rashGuardService,
      };
      
      const service = servicos[this.tipoProduto as "BERMUDA" | "FAIXA" | "KIMONO" | "RASH_GUARD"];
      if (service) {
        const json = await service.getById(idProduto);

        if (this.tipoProduto === "BERMUDA"){
          this.produto = <Bermuda>(json);
        } else if (this.tipoProduto === "FAIXA"){
          this.produto = <Faixa>(json);
        } else if (this.tipoProduto === "KIMONO"){
          this.produto = <Kimono>(json);
        } else {
          this.produto = <Rash_Guard>(json);
        }

        console.log(this.produto);

        // Preencher os campos comuns a todos os produtos
        this.formGroup.get('idMarca')?.setValue(this.produto.idMarca);
        this.formGroup.get('idModelo')?.setValue(this.produto.idModelo);
        this.formGroup.get('SKU')?.setValue(this.produto.SKU);
        this.formGroup.get('faixaEtaria')?.setValue(this.produto.faixaEtaria);
        this.formGroup.get('idTamanho')?.setValue(this.produto.idTamanho);
        this.formGroup.get('sexo')?.setValue(this.produto.sexo);
        this.formGroup.get('idCor')?.setValue(this.produto.idCor);

        // Preencher os campos específicos com base no tipo de produto
      }
    }
  }

  ngOnInit() {
    this.loadProdutoIfExists();
  }

  async save() {
    this.produto.idMarca = this.formGroup.value.idMarca;
    this.produto.idModelo = this.formGroup.value.idModelo;
    this.produto.SKU = this.formGroup.value.SKU;
    this.produto.faixaEtaria = this.formGroup.value.faixaEtaria;
    this.produto.idTamanho = this.formGroup.value.idTamanho;
    this.produto.sexo = this.formGroup.value.sexo;
    this.produto.idCor = this.formGroup.value.idCor;

    if (this.tipoProduto === "BERMUDA") {
      let bermuda: Bermuda = <Bermuda>(this.produto);
      if (this.produto.idProduto == 0) {

        this.bermudaService.insert(bermuda).then((json) => {
          bermuda = <Bermuda>(json);
          if (bermuda) {
            this.showMessage('Bermuda inserida com sucesso!');
            this.navController.navigateBack('/produtos');
          } else {
            this.showMessage('Erro ao inserir a bermuda.')
          }
        })
          .catch((error) => {
            this.showMessage('Erro ao inserir a bermuda: ' + error['mensage']);
          });
      } else {
        this.bermudaService.update(bermuda).then((json) => {
          bermuda = <Bermuda>(json);
          if (bermuda) {
            this.showMessage('Bermuda atualizado com sucesso!');
            this.navController.navigateBack('/produtos');
          } else {
            this.showMessage('Erro ao atualizar a bermuda.')
          }
        })
          .catch((error) => {
            this.showMessage('Erro ao atualizar a bermuda: ' + error['mensage']);
          });
      }
    }
  }

  async showMessage(texto: string) {
    const toast = await this.toastController.create({
      message: texto,
      duration: 1500
    });
    toast.present();
  }
}
