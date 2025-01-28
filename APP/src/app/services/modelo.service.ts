import { Injectable } from '@angular/core';
import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Modelo } from '../model/modelo';

@Injectable({
  providedIn: 'root'
})
export class ModeloService {

  httpHeaders = {
    headers: new HttpHeaders({ 'Content-Type': 'application/json' })
  }

  url: string = 'http://localhost:3000/armor/modelo/';

  constructor(private httpClient: HttpClient) { }

  async getById(idModelo: number) {
    return await this.httpClient.get(this.url + "" + idModelo).toPromise();
  }

  async getAll() {
    return await this.httpClient.get(this.url).toPromise();
  }

  async insert(modelo: Modelo) {
    return await this.httpClient.post(this.url, JSON.stringify(modelo), this.httpHeaders).toPromise();
  }

  async update(modelo: Modelo) {
    return await this.httpClient.put(this.url, JSON.stringify(modelo), this.httpHeaders).toPromise();
  }

  async delete(idModelo: number) {
    return await this.httpClient.delete(this.url + "" + idModelo).toPromise();
  }
}
