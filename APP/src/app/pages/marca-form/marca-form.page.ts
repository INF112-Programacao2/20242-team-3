import { Component, OnInit } from '@angular/core';
import { FormBuilder, FormGroup, ReactiveFormsModule, Validators } from '@angular/forms';
import { ActivatedRoute } from '@angular/router';
import { IonicModule, NavController, ToastController } from '@ionic/angular';
import { Cor } from 'src/app/model/cor';
import { Marca } from 'src/app/model/marca';
import { CorService } from 'src/app/services/cor.service';
import { MarcaService } from 'src/app/services/marca.service';

@Component({
  selector: 'app-marca-form',
  templateUrl: './marca-form.page.html',
  styleUrls: ['./marca-form.page.scss'],
  imports: [IonicModule, ReactiveFormsModule]
})
export class MarcaFormPage implements OnInit {
  marca: Marca;
  formGroup: FormGroup;

  constructor(private marcaService: MarcaService, private activatedRoute: ActivatedRoute, private formBuilder: FormBuilder,
    private navController: NavController, private toastController: ToastController) {

    this.marca = new Marca();

    this.formGroup = formBuilder.group({
      'nome': [this.marca.nome, Validators.compose([
        Validators.required,
      ])],
    });

    let idMarca = this.activatedRoute.snapshot.params['idMarca'];
    if (idMarca != null) {
      this.marcaService.getById(idMarca).then((json) => {
        this.marca = <Marca>(json);
        console.log(this.marca);
        this.formGroup.get('nome')?.setValue(this.marca.nome);
      });
    }
  }

  ngOnInit() { }

  async save() {
    this.marca.nome = this.formGroup.value.nome;

    if (this.marca.idMarca == 0) {
      this.marcaService.insert(this.marca).then((json) => {
        this.marca = <Marca>(json);
        if (this.marca) {
          this.showMessage('Marca inserida com sucesso!');
          this.navController.navigateBack('/marcas');
        } else {
          this.showMessage('Erro ao inserir a marca.')
        }
      })
        .catch((error) => {
          this.showMessage('Erro ao inserir a marca: ' + error['mensage']);
        });
    } else {
      this.marcaService.update(this.marca).then((json) => {
        this.marca = <Marca>(json);
        if (this.marca) {
          this.showMessage('Marca atualizada com sucesso!');
          this.navController.navigateBack('/marcas');
        } else {
          this.showMessage('Erro ao atualizar a marca.')
        }
      })
        .catch((error) => {
          this.showMessage('Erro ao atualizar a marca: ' + error['mensage']);
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
