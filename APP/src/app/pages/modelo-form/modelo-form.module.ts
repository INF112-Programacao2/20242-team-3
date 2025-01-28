import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';

import { IonicModule } from '@ionic/angular';

import { ModeloFormPageRoutingModule } from './modelo-form-routing.module';

import { ModeloFormPage } from './modelo-form.page';

@NgModule({
  imports: [
    CommonModule,
    FormsModule,
    IonicModule,
    ModeloFormPageRoutingModule,
    ModeloFormPage
  ],
  declarations: []
})
export class ModeloFormPageModule {}
