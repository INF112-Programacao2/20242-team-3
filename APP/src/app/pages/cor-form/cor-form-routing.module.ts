import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';

import { CorFormPage } from './cor-form.page';

const routes: Routes = [
  {
    path: '',
    component: CorFormPage
  }
];

@NgModule({
  imports: [RouterModule.forChild(routes)],
  exports: [RouterModule],
})
export class CorFormPageRoutingModule {}
