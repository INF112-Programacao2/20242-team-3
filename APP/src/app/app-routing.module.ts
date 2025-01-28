import { NgModule } from '@angular/core';
import { PreloadAllModules, RouterModule, Routes } from '@angular/router';

const routes: Routes = [
  {
    path: 'cor-form',
    loadChildren: () => import('./pages/cor-form/cor-form.module').then(m => m.CorFormPageModule)
  },
  {
    path: 'cor-form/:idCor',
    loadChildren: () => import('./pages/cor-form/cor-form.module').then(m => m.CorFormPageModule)
  },
  {
    path: 'cores',
    loadChildren: () => import('./pages/cores/cores.module').then(m => m.CoresPageModule)
  },
  {
    path: 'login',
    loadChildren: () => import('./pages/login/login.module').then(m => m.LoginPageModule)
  },
  {
    path: '',
    redirectTo: 'login',
    pathMatch: 'full'
  },
  {
    path: 'home',
    loadChildren: () => import('./pages/home/home.module').then(m => m.HomePageModule)
  },
  {
    path: 'tamanhos',
    loadChildren: () => import('./pages/tamanhos/tamanhos.module').then(m => m.TamanhosPageModule)
  },
  {
    path: 'tamanho-form',
    loadChildren: () => import('./pages/tamanho-form/tamanho-form.module').then(m => m.TamanhoFormPageModule)
  },
  {
    path: 'tamanho-form/:idTamanho',
    loadChildren: () => import('./pages/tamanho-form/tamanho-form.module').then(m => m.TamanhoFormPageModule)
  },
  {
    path: 'marca-form',
    loadChildren: () => import('./pages/marca-form/marca-form.module').then(m => m.MarcaFormPageModule)
  },
  {
    path: 'marca-form/:idMarca',
    loadChildren: () => import('./pages/marca-form/marca-form.module').then(m => m.MarcaFormPageModule)
  },
  {
    path: 'marcas',
    loadChildren: () => import('./pages/marcas/marcas.module').then(m => m.MarcasPageModule)
  },
  {
    path: 'modelo-form',
    loadChildren: () => import('./pages/modelo-form/modelo-form.module').then(m => m.ModeloFormPageModule)
  },
  {
    path: 'modelo-form/:idModelo',
    loadChildren: () => import('./pages/modelo-form/modelo-form.module').then(m => m.ModeloFormPageModule)
  },
  {
    path: 'modelos',
    loadChildren: () => import('./pages/modelos/modelos.module').then(m => m.ModelosPageModule)
  },
  {
    path: 'funcionarios',
    loadChildren: () => import('./pages/funcionarios/funcionarios.module').then(m => m.FuncionariosPageModule)
  },
  {
    path: 'funcionario-form',
    loadChildren: () => import('./pages/funcionario-form/funcionario-form.module').then(m => m.FuncionarioFormPageModule)
  },
  {
    path: 'funcionario-form/:idFuncionario',
    loadChildren: () => import('./pages/funcionario-form/funcionario-form.module').then(m => m.FuncionarioFormPageModule)
  },
  {
    path: 'clientes',
    loadChildren: () => import('./pages/clientes/clientes.module').then(m => m.ClientesPageModule)
  },
  {
    path: 'cliente-form',
    loadChildren: () => import('./pages/cliente-form/cliente-form.module').then(m => m.ClienteFormPageModule)
  },
  {
    path: 'cliente-form/:idCliente',
    loadChildren: () => import('./pages/cliente-form/cliente-form.module').then(m => m.ClienteFormPageModule)
  },
  {
    path: 'pesquisa',
    loadChildren: () => import('./pages/pesquisa/pesquisa.module').then(m => m.PesquisaPageModule)
  },
  {
    path: 'vendas',
    loadChildren: () => import('./pages/vendas/vendas.module').then(m => m.VendasPageModule)
  },
  {
    path: 'venda-form',
    loadChildren: () => import('./pages/venda-form/venda-form.module').then(m => m.VendaFormPageModule)
  },
  {
    path: 'venda-form/:idCliente',
    loadChildren: () => import('./pages/venda-form/venda-form.module').then(m => m.VendaFormPageModule)
  },
  {
    path: 'produtos',
    loadChildren: () => import('./pages/produtos/produtos.module').then(m => m.ProdutosPageModule)
  },
  {
    path: 'produto-form',
    loadChildren: () => import('./pages/produto-form/produto-form.module').then(m => m.ProdutoFormPageModule)
  },
  {
    path: 'produto-form/:idProduto',
    loadChildren: () => import('./pages/produto-form/produto-form.module').then(m => m.ProdutoFormPageModule)
  },
];

@NgModule({
  imports: [
    RouterModule.forRoot(routes, { preloadingStrategy: PreloadAllModules })
  ],
  exports: [RouterModule]
})
export class AppRoutingModule { }
