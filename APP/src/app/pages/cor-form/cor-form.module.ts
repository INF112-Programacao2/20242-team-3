import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule, ReactiveFormsModule } from '@angular/forms';

import { IonicModule } from '@ionic/angular';

import { CorFormPageRoutingModule } from './cor-form-routing.module';

import { CorFormPage } from './cor-form.page';

@NgModule({
  imports: [
    CommonModule,
    FormsModule,
    IonicModule,
    CorFormPageRoutingModule,
    CorFormPage,
    ReactiveFormsModule
  ],
  declarations: []
})
export class CorFormPageModule {}
