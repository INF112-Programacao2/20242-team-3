import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';

import { IonicModule } from '@ionic/angular';

import { MarcaFormPageRoutingModule } from './marca-form-routing.module';

import { MarcaFormPage } from './marca-form.page';

@NgModule({
  imports: [
    CommonModule,
    FormsModule,
    IonicModule,
    MarcaFormPageRoutingModule,
    MarcaFormPage
  ],
  declarations: []
})
export class MarcaFormPageModule {}
