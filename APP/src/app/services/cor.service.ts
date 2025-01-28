import { Injectable } from '@angular/core';
import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Cor } from '../model/cor';

@Injectable({
  providedIn: 'root'
})
export class CorService {

  httpHeaders = {
    headers: new HttpHeaders({ 'Content-Type': 'application/json' })
  }

  url: string = 'http://localhost:3000/armor/cor/';

  constructor(private httpClient: HttpClient) { }

  async getById(idCor: number) {
    return await this.httpClient.get(this.url + "" + idCor).toPromise();
  }

  async getAll() {
    return await this.httpClient.get(this.url).toPromise();
  }

  async insert(cor: Cor) {
    return await this.httpClient.post(this.url, JSON.stringify(cor), this.httpHeaders).toPromise();
  }

  async update(cor: Cor) {
    return await this.httpClient.put(this.url, JSON.stringify(cor), this.httpHeaders).toPromise();
  }

  async delete(idCor: number) {
    return await this.httpClient.delete(this.url + "" + idCor).toPromise();
  }
}