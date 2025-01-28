import { ComponentFixture, TestBed } from '@angular/core/testing';
import { MarcaFormPage } from './marca-form.page';

describe('MarcaFormPage', () => {
  let component: MarcaFormPage;
  let fixture: ComponentFixture<MarcaFormPage>;

  beforeEach(() => {
    fixture = TestBed.createComponent(MarcaFormPage);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
