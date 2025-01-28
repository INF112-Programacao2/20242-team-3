import { TestBed } from '@angular/core/testing';

import { RashGuardService } from './rash-guard.service';

describe('RashGuardService', () => {
  let service: RashGuardService;

  beforeEach(() => {
    TestBed.configureTestingModule({});
    service = TestBed.inject(RashGuardService);
  });

  it('should be created', () => {
    expect(service).toBeTruthy();
  });
});
