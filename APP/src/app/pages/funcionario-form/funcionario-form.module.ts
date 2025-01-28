import { NgModule } from '@angular/core';
import { CommonModule } from '@angular/common';
import { FormsModule } from '@angular/forms';

import { IonicModule } from '@ionic/angular';

import { FuncionarioFormPageRoutingModule } from './funcionario-form-routing.module';

import { FuncionarioFormPage } from './funcionario-form.page';

@NgModule({
  imports: [
    CommonModule,
    FormsModule,
    IonicModule,
    FuncionarioFormPageRoutingModule,
    FuncionarioFormPage
  ],
  declarations: []
})
export class FuncionarioFormPageModule {}
