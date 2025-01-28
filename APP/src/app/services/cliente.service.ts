import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { Cliente } from '../model/cliente';

@Injectable({
  providedIn: 'root'
})
export class ClienteService {

  httpHeaders = {
    headers: new HttpHeaders({ 'Content-Type': 'application/json' })
  }

  url: string = 'http://localhost:3000/armor/cliente/';

  constructor(private httpClient: HttpClient) { }

  async getById(idPessoa: number) {
    return await this.httpClient.get(this.url + "" + idPessoa).toPromise();
  }

  async getAll() {
    return await this.httpClient.get(this.url).toPromise();
  }

  async insert(cliente: Cliente) {
    return await this.httpClient.post(this.url, JSON.stringify(cliente), this.httpHeaders).toPromise();
  }

  async update(cliente: Cliente) {
    return await this.httpClient.put(this.url, JSON.stringify(cliente), this.httpHeaders).toPromise();
  }

  async delete(idPessoa: number) {
    return await this.httpClient.delete(this.url + "" + idPessoa).toPromise();
  }
}
