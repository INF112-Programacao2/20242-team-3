import { Injectable } from '@angular/core';
import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Rash_Guard } from '../model/rash-guard';


@Injectable({
  providedIn: 'root'
})
export class RashGuardService {

  httpHeaders = {
    headers: new HttpHeaders({ 'Content-Type': 'application/json' })
  }

  url: string = 'http://localhost:3000/armor/produtos/rash_guard/';

  constructor(private httpClient: HttpClient) { }

  async getById(idRash_Guard: number) {
    return await this.httpClient.get(this.url + "" + idRash_Guard).toPromise();
  }

  async getAll() {
    return await this.httpClient.get(this.url).toPromise();
  }

  async insert(rash_Guard: Rash_Guard) {
    return await this.httpClient.post(this.url, JSON.stringify(rash_Guard), this.httpHeaders).toPromise();
  }

  async update(rash_Guard: Rash_Guard) {
    return await this.httpClient.put(this.url, JSON.stringify(rash_Guard), this.httpHeaders).toPromise();
  }

  async delete(idRash_Guard: number) {
    return await this.httpClient.delete(this.url + "" + idRash_Guard).toPromise();
  }
}
