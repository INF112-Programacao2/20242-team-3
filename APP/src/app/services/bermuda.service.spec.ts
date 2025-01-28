import { TestBed } from '@angular/core/testing';

import { BermudaService } from './bermuda.service';

describe('BermudaService', () => {
  let service: BermudaService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(BermudaService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
