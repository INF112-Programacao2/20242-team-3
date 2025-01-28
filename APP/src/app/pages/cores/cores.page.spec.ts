import { ComponentFixture, TestBed } from '@angular/core/testing';
import { CoresPage } from './cores.page';

describe('CoresPage', () => {
  let component: CoresPage;
  let fixture: ComponentFixture<CoresPage>;

  beforeEach(() => {
    fixture = TestBed.createComponent(CoresPage);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
