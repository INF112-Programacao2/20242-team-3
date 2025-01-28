import { CommonModule } from '@angular/common';
import { Component, OnInit } from '@angular/core';
import { FormBuilder, FormGroup, ReactiveFormsModule, Validators } from '@angular/forms';
import { ActivatedRoute } from '@angular/router';
import { IonicModule, LoadingController, NavController, ToastController } from '@ionic/angular';
import { Marca } from 'src/app/model/marca';
import { Modelo } from 'src/app/model/modelo';
import { MarcaService } from 'src/app/services/marca.service';
import { ModeloService } from 'src/app/services/modelo.service';

@Component({
  selector: 'app-modelo-form',
  templateUrl: './modelo-form.page.html',
  styleUrls: ['./modelo-form.page.scss'],
  imports: [IonicModule, ReactiveFormsModule, CommonModule]
})
export class ModeloFormPage implements OnInit {
  marcas: Marca[];
  modelo: Modelo;
  formGroup: FormGroup;

  constructor(private marcaService: MarcaService, private modeloService: ModeloService, private activatedRoute: ActivatedRoute, private formBuilder: FormBuilder,
    private navController: NavController, private toastController: ToastController, private loadingController: LoadingController) {

    this.marcas = [];
    this.modelo = new Modelo();

    this.formGroup = formBuilder.group({
      'nome': [this.modelo.nome, Validators.compose([
        Validators.required,
      ])],
      'idMarca': [this.modelo.idMarca, Validators.compose([
        Validators.required,
      ])],
    });

    let idModelo = this.activatedRoute.snapshot.params['idModelo'];
    if (idModelo != null) {
      this.modeloService.getById(idModelo).then((json) => {
        this.modelo = <Modelo>(json);
        this.formGroup.get('nome')?.setValue(this.modelo.nome);
        this.formGroup.get('idMarca')?.setValue(this.modelo.idMarca);
      });
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

  ngOnInit() { }

  async save() {
    this.modelo.nome = this.formGroup.value.nome;

    if (this.modelo.idModelo == 0) {
      this.modeloService.insert(this.modelo).then((json) => {
        this.modelo = <Modelo>(json);
        if (this.modelo) {
          this.showMessage('Modelo inserido com sucesso!');
          this.navController.navigateBack('/modelos');
        } else {
          this.showMessage('Erro ao inserir o modelo.')
        }
      })
        .catch((error) => {
          this.showMessage('Erro ao inserir o modelo: ' + error['mensage']);
        });
    } else {
      this.modeloService.update(this.modelo).then((json) => {
        this.modelo = <Modelo>(json);
        if (this.modelo) {
          this.showMessage('Modelo atualizado com sucesso!');
          this.navController.navigateBack('/modelos');
        } else {
          this.showMessage('Erro ao atualizar o modelo.')
        }
      })
        .catch((error) => {
          this.showMessage('Erro ao atualizar o modelo: ' + error['mensage']);
        });
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
