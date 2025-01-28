import { CommonModule } from '@angular/common';
import { Component, OnInit } from '@angular/core';
import { FormBuilder, FormGroup, ReactiveFormsModule, Validators } from '@angular/forms';
import { IonicModule, NavController, ToastController } from '@ionic/angular';
import { Funcionario } from 'src/app/model/funcionario';
import { FuncionarioService } from 'src/app/services/funcionario.service';
import { LoginService } from 'src/app/services/login.service';

@Component({
  selector: 'app-login',
  templateUrl: './login.page.html',
  styleUrls: ['./login.page.scss'],
  imports: [IonicModule, CommonModule, ReactiveFormsModule]
})
export class LoginPage implements OnInit {
  formGroup: FormGroup;

  constructor(private funcionarioService: FuncionarioService, private loginService: LoginService, private formBuilder: FormBuilder, private navController: NavController, private toastController: ToastController) {
    if (this.funcionarioService.isSessionActive()) {
      this.showMessage("Bem vindo de volta!");
      this.navController.navigateBack('/home');
    }

    this.formGroup = formBuilder.group({
      'email': [, Validators.compose([
        Validators.email,
        Validators.required,
      ])],
      'senha': [, Validators.compose([
        Validators.required,
      ])],
    });
  }

  ngOnInit() { }

  async login() {
    await this.loginService.login(this.formGroup.value.email, this.formGroup.value.senha).then((json) => {
      let funcionario = <Funcionario>(json);
      console.log(funcionario);
      if (<Funcionario>(json) === null) {
        this.showMessage('Usuário não encontrado.');
      } else {
        this.showMessage('Bem vindo ao sistema!');
        this.funcionarioService.saveSession(funcionario.idPessoa);
        this.navController.navigateBack('/home')
      }
    });
  }

  async showMessage(texto: string) {
    const toast = await this.toastController.create({
      message: texto,
      duration: 1500
    });
    toast.present();
  }
}
