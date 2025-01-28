import { CommonModule } from '@angular/common';
import { Component, OnInit } from '@angular/core';
import { RouterLink } from '@angular/router';
import { IonicModule, NavController, ToastController } from '@ionic/angular';
import { Funcionario } from 'src/app/model/funcionario';
import { FuncionarioService } from 'src/app/services/funcionario.service';

@Component({
  selector: 'app-home',
  templateUrl: './home.page.html',
  styleUrls: ['./home.page.scss'],
  imports: [IonicModule, RouterLink, CommonModule]
})
export class HomePage implements OnInit {
  isGerente: boolean;
  funcionario: Funcionario;

  public appPages = [
    { title: 'Clientes', url: '/clientes', icon: 'cart-outline', color: 'salmon' },
    { title: 'Produtos', url: '/produtos', icon: 'bookmark', color: 'danger' },
    { title: 'Vendas', url: '/vendas', icon: 'power', color: 'intense-red' },
    { title: 'Pesquisar', url: '/pesquisa', icon: 'power', color: 'intense-red' },
    { title: 'Sair', url: '/home', icon: 'power', color: 'intense-red' },
  ];

  public appGerentePages = [
    { title: 'Cores', url: '/cores', icon: 'bug', color: 'intense-red' },
    { title: 'Modelos', url: '/modelos', icon: 'apps', color: 'intense-red' },
    { title: 'Marcas', url: '/marcas', icon: 'apps', color: 'intense-red' },
    { title: 'Tamanhos', url: '/tamanhos', icon: 'apps', color: 'intense-red' },
    { title: 'Funcionários', url: '/funcionarios', icon: 'apps', color: 'intense-red' },
  ];

  constructor(private toastController: ToastController, private navController: NavController,
    private funcionarioService: FuncionarioService) {
    this.isGerente = true;
    this.funcionario = new Funcionario();

    this.funcionarioService.getById(this.funcionarioService.recoverSession()).then((json) => {
      this.funcionario = <Funcionario>(json);

      // this.funcionarioService.checkGerente(this.funcionario.email).then((json) => {
      //   this.isGerente = <boolean>(json);
      // });
    });
  }

  ngOnInit() { }

  async showMessage(texto: string) {
    const toast = await this.toastController.create({
      message: texto,
      duration: 1500
    })
    toast.present();
  }
}
