import { TestBed } from '@angular/core/testing';

import { FaixaService } from './faixa.service';

describe('FaixaService', () => {
  let service: FaixaService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(FaixaService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
