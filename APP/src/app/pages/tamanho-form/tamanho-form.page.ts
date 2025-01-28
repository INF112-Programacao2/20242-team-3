import { Component, OnInit } from '@angular/core';
import { FormBuilder, FormGroup, ReactiveFormsModule, Validators } from '@angular/forms';
import { ActivatedRoute } from '@angular/router';
import { IonicModule, NavController, ToastController } from '@ionic/angular';
import { Tamanho } from 'src/app/model/tamanho';
import { TamanhoService } from 'src/app/services/tamanho.service';

@Component({
  selector: 'app-tamanho-form',
  templateUrl: './tamanho-form.page.html',
  styleUrls: ['./tamanho-form.page.scss'],
  imports: [IonicModule, ReactiveFormsModule]
})

export class TamanhoFormPage implements OnInit {
  tamanho: Tamanho;
  formGroup: FormGroup;

  constructor(private tamanhoService: TamanhoService, private activatedRoute: ActivatedRoute, private formBuilder: FormBuilder,
    private navController: NavController, private toastController: ToastController) {

    this.tamanho = new Tamanho();

    this.formGroup = formBuilder.group({
      'nome': [this.tamanho.nome, Validators.compose([
        Validators.required,
      ])],
      'tipoProduto': [this.tamanho.tipoProduto, Validators.compose([
        Validators.required,
      ])],
    });

    let idTamanho = this.activatedRoute.snapshot.params['idTamanho'];
    if (idTamanho != null) {
      this.tamanhoService.getById(idTamanho).then((json) => {
        this.tamanho = <Tamanho>(json);
        this.formGroup.get('nome')?.setValue(this.tamanho.nome);
        this.formGroup.get('tipoProduto')?.setValue(this.tamanho.tipoProduto);
      });
    }
  }

  ngOnInit() { }

  async save() {
    this.tamanho.nome = this.formGroup.value.nome;

    if (this.tamanho.idTamanho == 0) {
      this.tamanhoService.insert(this.tamanho).then((json) => {
        this.tamanho = <Tamanho>(json);
        if (this.tamanho) {
          this.showMessage('Tamanho inserido com sucesso!');
          this.navController.navigateBack('/tamanhos');
        } else {
          this.showMessage('Erro ao inserir o tamanho.')
        }
      })
        .catch((error) => {
          this.showMessage('Erro ao inserir o tamanho: ' + error['mensage']);
        });
    } else {
      this.tamanhoService.update(this.tamanho).then((json) => {
        this.tamanho = <Tamanho>(json);
        if (this.tamanho) {
          this.showMessage('Tamanho atualizado com sucesso!');
          this.navController.navigateBack('/tamanhos');
        } else {
          this.showMessage('Erro ao atualizar o tamanho.')
        }
      })
        .catch((error) => {
          this.showMessage('Erro ao atualizar o tamanho: ' + error['mensage']);
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