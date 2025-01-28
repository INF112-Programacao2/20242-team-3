import { TestBed } from '@angular/core/testing';

import { KimonoService } from './kimono.service';

describe('KimonoService', () => {
  let service: KimonoService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(KimonoService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
