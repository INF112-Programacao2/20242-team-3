import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';

import { IonicModule } from '@ionic/angular';

import { ProdutoFormPageRoutingModule } from './produto-form-routing.module';

import { ProdutoFormPage } from './produto-form.page';

@NgModule({
  imports: [
    CommonModule,
    FormsModule,
    IonicModule,
    ProdutoFormPageRoutingModule,
    ProdutoFormPage
  ],
  declarations: []
})
export class ProdutoFormPageModule {}
