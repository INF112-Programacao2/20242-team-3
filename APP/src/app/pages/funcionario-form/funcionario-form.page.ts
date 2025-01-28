import { Component, OnInit } from '@angular/core';
import { FormBuilder, FormGroup, ReactiveFormsModule, Validators } from '@angular/forms';
import { ActivatedRoute } from '@angular/router';
import { IonicModule, NavController, ToastController } from '@ionic/angular';
import { Funcionario } from 'src/app/model/funcionario';
import { FuncionarioService } from 'src/app/services/funcionario.service';

@Component({
  selector: 'app-funcionario-form',
  templateUrl: './funcionario-form.page.html',
  styleUrls: ['./funcionario-form.page.scss'],
  imports: [IonicModule, ReactiveFormsModule]
})
export class FuncionarioFormPage implements OnInit {
  funcionario: Funcionario;
  formGroup: FormGroup;

  constructor(private funcionarioService: FuncionarioService, private activatedRoute: ActivatedRoute, private formBuilder: FormBuilder,
    private navController: NavController, private toastController: ToastController) {

    this.funcionario = new Funcionario();

    this.formGroup = formBuilder.group({
      'nome': [this.funcionario.nome, Validators.compose([
        Validators.required,
      ])],
      'nascimento': [this.funcionario.nascimento, Validators.compose([
        Validators.required,
      ])],
      'telefone': [this.funcionario.telefone, Validators.compose([
        Validators.required,
        Validators.maxLength(11),
        Validators.minLength(11)
      ])],
      'cpf': [this.funcionario.cpf, Validators.compose([
        Validators.required,
        Validators.maxLength(15),
        Validators.minLength(15)
      ])],
      'idade': [this.funcionario.idade, Validators.compose([
        Validators.required,
        Validators.min(0),
      ])],
      'sexo': [this.funcionario.sexo, Validators.compose([
        Validators.required,
      ])],
      'email': [this.funcionario.email, Validators.compose([
        Validators.email,
        Validators.required,
      ])],
      'senha': [this.funcionario.senha, Validators.compose([
        Validators.required,
        Validators.minLength(8),
      ])],
    });

    let idFuncionario = this.activatedRoute.snapshot.params['idFuncionario'];
    if (idFuncionario != null) {
      this.funcionarioService.getById(idFuncionario).then((json) => {
        this.funcionario = <Funcionario>(json);
        console.log(this.funcionario);
        this.formGroup.get('nome')?.setValue(this.funcionario.nome);
        this.formGroup.get('nascimento')?.setValue(this.funcionario.nascimento);
        this.formGroup.get('telefone')?.setValue(this.funcionario.telefone);
        this.formGroup.get('cpf')?.setValue(this.funcionario.cpf);
        this.formGroup.get('idade')?.setValue(this.funcionario.idade);
        this.formGroup.get('sexo')?.setValue(this.funcionario.sexo);
        this.formGroup.get('email')?.setValue(this.funcionario.emailDecrypted);
        this.formGroup.get('senha')?.setValue(this.funcionario.senha);
      });
    }
  }

  ngOnInit() { }

  async save() {
    this.funcionario.nome = this.formGroup.value.nome;

    if (this.funcionario.idPessoa == 0) {
      this.funcionarioService.insert(this.funcionario).then((json) => {
        this.funcionario = <Funcionario>(json);
        if (this.funcionario) {
          this.showMessage('funcionário inserido com sucesso!');
          this.navController.navigateBack('/funcionarios');
        } else {
          this.showMessage('Erro ao inserir o funcionário.')
        }
      })
        .catch((error) => {
          this.showMessage('Erro ao inserir o funcionário: ' + error['mensage']);
        });
    } else {
      this.funcionarioService.update(this.funcionario).then((json) => {
        this.funcionario = <Funcionario>(json);
        if (this.funcionario) {
          this.showMessage('funcionário atualizado com sucesso!');
          this.navController.navigateBack('/funcionarios');
        } else {
          this.showMessage('Erro ao atualizar o funcionário.')
        }
      })
        .catch((error) => {
          this.showMessage('Erro ao atualizar a funcionário: ' + error['mensage']);
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
