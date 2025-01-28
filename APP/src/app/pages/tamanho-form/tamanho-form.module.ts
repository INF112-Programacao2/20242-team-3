import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';

import { IonicModule } from '@ionic/angular';

import { TamanhoFormPageRoutingModule } from './tamanho-form-routing.module';

import { TamanhoFormPage } from './tamanho-form.page';

@NgModule({
  imports: [
    CommonModule,
    FormsModule,
    IonicModule,
    TamanhoFormPageRoutingModule,
    TamanhoFormPage
  ],
  declarations: []
})
export class TamanhoFormPageModule {}
