import { ComponentFixture, TestBed } from '@angular/core/testing';
import { CorFormPage } from './cor-form.page';

describe('CorFormPage', () => {
  let component: CorFormPage;
  let fixture: ComponentFixture<CorFormPage>;

  beforeEach(() => {
    fixture = TestBed.createComponent(CorFormPage);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
