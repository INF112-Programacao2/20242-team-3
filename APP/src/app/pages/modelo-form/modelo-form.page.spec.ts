import { ComponentFixture, TestBed } from '@angular/core/testing';
import { ModeloFormPage } from './modelo-form.page';

describe('ModeloFormPage', () => {
  let component: ModeloFormPage;
  let fixture: ComponentFixture<ModeloFormPage>;

  beforeEach(() => {
    fixture = TestBed.createComponent(ModeloFormPage);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
