import { ComponentFixture, TestBed } from '@angular/core/testing';
import { FuncionarioFormPage } from './funcionario-form.page';

describe('FuncionarioFormPage', () => {
  let component: FuncionarioFormPage;
  let fixture: ComponentFixture<FuncionarioFormPage>;

  beforeEach(() => {
    fixture = TestBed.createComponent(FuncionarioFormPage);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
