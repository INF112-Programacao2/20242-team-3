import { ComponentFixture, TestBed } from '@angular/core/testing';
import { TamanhoFormPage } from './tamanho-form.page';

describe('TamanhoFormPage', () => {
  let component: TamanhoFormPage;
  let fixture: ComponentFixture<TamanhoFormPage>;

  beforeEach(() => {
    fixture = TestBed.createComponent(TamanhoFormPage);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
