import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';

import { IonicModule } from '@ionic/angular';

import { VendaFormPageRoutingModule } from './venda-form-routing.module';

import { VendaFormPage } from './venda-form.page';

@NgModule({
  imports: [
    CommonModule,
    FormsModule,
    IonicModule,
    VendaFormPageRoutingModule,
    VendaFormPage
  ],
  declarations: []
})
export class VendaFormPageModule {}
