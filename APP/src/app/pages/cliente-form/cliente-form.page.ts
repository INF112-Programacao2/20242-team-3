import { Component, OnInit } from '@angular/core';
import { FormBuilder, FormGroup, ReactiveFormsModule, Validators } from '@angular/forms';
import { ActivatedRoute } from '@angular/router';
import { IonicModule, NavController, ToastController } from '@ionic/angular';
import { Cliente } from 'src/app/model/cliente';
import { ClienteService } from 'src/app/services/cliente.service';

@Component({
  selector: 'app-cliente-form',
  templateUrl: './cliente-form.page.html',
  styleUrls: ['./cliente-form.page.scss'],
  imports: [IonicModule, ReactiveFormsModule]
})
export class ClienteFormPage implements OnInit {
  cliente: Cliente;
  formGroup: FormGroup;

  constructor(private clienteService: ClienteService, private activatedRoute: ActivatedRoute, private formBuilder: FormBuilder,
    private navController: NavController, private toastController: ToastController) {

    this.cliente = new Cliente();

    this.formGroup = formBuilder.group({
      'nome': [this.cliente.nome, Validators.compose([
        Validators.required,
      ])],
      'nascimento': [this.cliente.nascimento, Validators.compose([
        Validators.required,
      ])],
      'telefone': [this.cliente.telefone, Validators.compose([
        Validators.required,
        Validators.maxLength(11),
        Validators.minLength(11)
      ])],
      'cpf': [this.cliente.cpf, Validators.compose([
        Validators.required,
        Validators.maxLength(15),
        Validators.minLength(15)
      ])],
      'idade': [this.cliente.idade, Validators.compose([
        Validators.required,
        Validators.min(0),
      ])],
      'sexo': [this.cliente.sexo, Validators.compose([
        Validators.required,
      ])],
      'envergadura': [this.cliente.envergadura, Validators.compose([
        Validators.required,
        Validators.min(0),
      ])],
      'peso': [this.cliente.peso, Validators.compose([
        Validators.required,
        Validators.min(0),
      ])],
      'altura': [this.cliente.altura, Validators.compose([
        Validators.required,
        Validators.min(0),
      ])],
      'torax': [this.cliente.torax, Validators.compose([
        Validators.required,
        Validators.min(0),
      ])],
      'cintura': [this.cliente.cintura, Validators.compose([
        Validators.required,
        Validators.min(0),
      ])],
    });

    let idcliente = this.activatedRoute.snapshot.params['idCliente'];
    if (idcliente != null) {
      this.clienteService.getById(idcliente).then((json) => {
        this.cliente = <Cliente>(json);
        console.log(this.cliente);
        this.formGroup.get('nome')?.setValue(this.cliente.nome);
        this.formGroup.get('nascimento')?.setValue(this.cliente.nascimento);
        this.formGroup.get('telefone')?.setValue(this.cliente.telefone);
        this.formGroup.get('cpf')?.setValue(this.cliente.cpf);
        this.formGroup.get('idade')?.setValue(this.cliente.idade);
        this.formGroup.get('sexo')?.setValue(this.cliente.sexo);
        this.formGroup.get('envergadura')?.setValue(this.cliente.envergadura);
        this.formGroup.get('peso')?.setValue(this.cliente.peso);
        this.formGroup.get('altura')?.setValue(this.cliente.altura);
        this.formGroup.get('torax')?.setValue(this.cliente.torax);
        this.formGroup.get('cintura')?.setValue(this.cliente.cintura);
      });
    }
  }

  ngOnInit() { }

  async save() {
    this.cliente.nome = this.formGroup.value.nome;

    if (this.cliente.idPessoa == 0) {
      this.clienteService.insert(this.cliente).then((json) => {
        this.cliente = <Cliente>(json);
        if (this.cliente) {
          this.showMessage('Cliente inserido com sucesso!');
          this.navController.navigateBack('/clientes');
        } else {
          this.showMessage('Erro ao inserir o cliente.')
        }
      })
        .catch((error) => {
          this.showMessage('Erro ao inserir o cliente: ' + error['mensage']);
        });
    } else {
      this.clienteService.update(this.cliente).then((json) => {
        this.cliente = <Cliente>(json);
        if (this.cliente) {
          this.showMessage('Cliente atualizado com sucesso!');
          this.navController.navigateBack('/clientes');
        } else {
          this.showMessage('Erro ao atualizar o cliente.')
        }
      })
        .catch((error) => {
          this.showMessage('Erro ao atualizar a cliente: ' + error['mensage']);
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
