import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';

import { MarcaFormPage } from './marca-form.page';

const routes: Routes = [
  {
    path: '',
    component: MarcaFormPage
  }
];

@NgModule({
  imports: [RouterModule.forChild(routes)],
  exports: [RouterModule],
})
export class MarcaFormPageRoutingModule {}
