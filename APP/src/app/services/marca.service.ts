import { Injectable } from '@angular/core';
import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Marca } from '../model/marca';

@Injectable({
  providedIn: 'root'
})
export class MarcaService {

  httpHeaders = {
    headers: new HttpHeaders({ 'Content-Type': 'application/json' })
  }

  url: string = 'http://localhost:3000/armor/marca/';

  constructor(private httpClient: HttpClient) { }

  async getById(idMarca: number) {
    return await this.httpClient.get(this.url + "" + idMarca).toPromise();
  }

  async getAll() {
    return await this.httpClient.get(this.url).toPromise();
  }

  async insert(marca: Marca) {
    return await this.httpClient.post(this.url, JSON.stringify(marca), this.httpHeaders).toPromise();
  }

  async update(marca: Marca) {
    return await this.httpClient.put(this.url, JSON.stringify(marca), this.httpHeaders).toPromise();
  }

  async delete(idMarca: number) {
    return await this.httpClient.delete(this.url + "" + idMarca).toPromise();
  }
}
