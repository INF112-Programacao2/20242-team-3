import { Component, OnInit } from '@angular/core';
import { FormBuilder, FormGroup, ReactiveFormsModule, Validators } from '@angular/forms';
import { ActivatedRoute } from '@angular/router';
import { IonicModule, NavController, ToastController } from '@ionic/angular';
import { Cor } from 'src/app/model/cor';
import { CorService } from 'src/app/services/cor.service';

@Component({
  selector: 'app-cor-form',
  templateUrl: './cor-form.page.html',
  styleUrls: ['./cor-form.page.scss'],
  imports: [IonicModule, ReactiveFormsModule]
})
export class CorFormPage implements OnInit {
  cor: Cor;
  formGroup: FormGroup;

  constructor(private corService: CorService, private activatedRoute: ActivatedRoute, private formBuilder: FormBuilder,
    private navController: NavController, private toastController: ToastController) {

    this.cor = new Cor();

    this.formGroup = formBuilder.group({
      'nome': [this.cor.nome, Validators.compose([
        Validators.required,
      ])],
    });

    let idCor = this.activatedRoute.snapshot.params['idCor'];
    if (idCor != null) {
      this.corService.getById(idCor).then((json) => {
        this.cor = <Cor>(json);
        this.formGroup.get('nome')?.setValue(this.cor.nome);
      });
    }
  }

  ngOnInit() { }

  async save() {
    this.cor.nome = this.formGroup.value.nome;

    if (this.cor.idCor == 0) {
      this.corService.insert(this.cor).then((json) => {
        this.cor = <Cor>(json);
        if (this.cor) {
          this.showMessage('Cor inserida com sucesso!');
          this.navController.navigateBack('/cores');
        } else {
          this.showMessage('Erro ao inserir a cor.')
        }
      })
        .catch((error) => {
          this.showMessage('Erro ao inserir a cor: ' + error['mensage']);
        });
    } else {
      this.corService.update(this.cor).then((json) => {
        this.cor = <Cor>(json);
        if (this.cor) {
          this.showMessage('Cor atualizada com sucesso!');
          this.navController.navigateBack('/cores');
        } else {
          this.showMessage('Erro ao atualizar a cor.')
        }
      })
        .catch((error) => {
          this.showMessage('Erro ao atualizar a cor: ' + error['mensage']);
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
