import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';

import { TamanhosPage } from './tamanhos.page';

const routes: Routes = [
  {
    path: '',
    component: TamanhosPage
  }
];

@NgModule({
  imports: [RouterModule.forChild(routes)],
  exports: [RouterModule],
})
export class TamanhosPageRoutingModule {}
