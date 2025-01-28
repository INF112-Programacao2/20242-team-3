import { Injectable } from '@angular/core';
import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Faixa } from '../model/faixa';

@Injectable({
  providedIn: 'root'
})
export class FaixaService {
  httpHeaders = {
    headers: new HttpHeaders({ 'Content-Type': 'application/json' })
  }

  url: string = 'http://localhost:3000/armor/produtos/faixa/';

  constructor(private httpClient: HttpClient) { }

  async getById(idFaixa: number) {
    return await this.httpClient.get(this.url + "" + idFaixa).toPromise();
  }

  async getAll() {
    return await this.httpClient.get(this.url).toPromise();
  }

  async insert(faixa: Faixa) {
    return await this.httpClient.post(this.url, JSON.stringify(faixa), this.httpHeaders).toPromise();
  }

  async update(faixa: Faixa) {
    return await this.httpClient.put(this.url, JSON.stringify(faixa), this.httpHeaders).toPromise();
  }

  async delete(idFaixa: number) {
    return await this.httpClient.delete(this.url + "" + idFaixa).toPromise();
  }
}