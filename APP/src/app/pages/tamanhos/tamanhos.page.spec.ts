import { ComponentFixture, TestBed } from '@angular/core/testing';
import { TamanhosPage } from './tamanhos.page';

describe('TamanhosPage', () => {
  let component: TamanhosPage;
  let fixture: ComponentFixture<TamanhosPage>;

  beforeEach(() => {
    fixture = TestBed.createComponent(TamanhosPage);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
