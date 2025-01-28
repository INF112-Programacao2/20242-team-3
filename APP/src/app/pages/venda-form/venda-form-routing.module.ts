import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';

import { VendaFormPage } from './venda-form.page';

const routes: Routes = [
  {
    path: '',
    component: VendaFormPage
  }
];

@NgModule({
  imports: [RouterModule.forChild(routes)],
  exports: [RouterModule],
})
export class VendaFormPageRoutingModule {}
