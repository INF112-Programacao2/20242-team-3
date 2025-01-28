import { Injectable } from '@angular/core';
import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Kimono } from '../model/kimono';

@Injectable({
  providedIn: 'root'
})
export class KimonoService {

  httpHeaders = {
    headers: new HttpHeaders({ 'Content-Type': 'application/json' })
  }

  url: string = 'http://localhost:3000/armor/produtos/kimono/';

  constructor(private httpClient: HttpClient) { }

  async getById(idKimono: number) {
    return await this.httpClient.get(this.url + "" + idKimono).toPromise();
  }

  async getAll() {
    return await this.httpClient.get(this.url).toPromise();
  }

  async insert(kimono: Kimono) {
    return await this.httpClient.post(this.url, JSON.stringify(kimono), this.httpHeaders).toPromise();
  }

  async update(kimono: Kimono) {
    return await this.httpClient.put(this.url, JSON.stringify(kimono), this.httpHeaders).toPromise();
  }

  async delete(idKimono: number) {
    return await this.httpClient.delete(this.url + "" + idKimono).toPromise();
  }
}
