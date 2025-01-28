import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';

import { FuncionarioFormPage } from './funcionario-form.page';

const routes: Routes = [
  {
    path: '',
    component: FuncionarioFormPage
  }
];

@NgModule({
  imports: [RouterModule.forChild(routes)],
  exports: [RouterModule],
})
export class FuncionarioFormPageRoutingModule {}
