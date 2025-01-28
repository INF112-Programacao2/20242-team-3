import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';

import { TamanhoFormPage } from './tamanho-form.page';

const routes: Routes = [
  {
    path: '',
    component: TamanhoFormPage
  }
];

@NgModule({
  imports: [RouterModule.forChild(routes)],
  exports: [RouterModule],
})
export class TamanhoFormPageRoutingModule {}
