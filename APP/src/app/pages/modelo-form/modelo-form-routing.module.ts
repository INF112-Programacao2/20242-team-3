import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';

import { ModeloFormPage } from './modelo-form.page';

const routes: Routes = [
  {
    path: '',
    component: ModeloFormPage
  }
];

@NgModule({
  imports: [RouterModule.forChild(routes)],
  exports: [RouterModule],
})
export class ModeloFormPageRoutingModule {}
