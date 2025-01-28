import { Injectable } from '@angular/core';
import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Tamanho } from '../model/tamanho';

@Injectable({
  providedIn: 'root'
})
export class TamanhoService {

  httpHeaders = {
    headers: new HttpHeaders({ 'Content-Type': 'application/json' })
  }

  url: string = 'http://localhost:3000/armor/tamanho';

  constructor(private httpClient: HttpClient) { }

  async getById(idTamanho: number) {
    return await this.httpClient.get(this.url + "/" + idTamanho).toPromise();
  }

  async getAll() {
    return await this.httpClient.get(this.url).toPromise();
  }

  async getAllByTipoProduto(tipoProduto: string) {
    return await this.httpClient.get(this.url + "/tipo-produto/" + tipoProduto).toPromise();
  }

  async insert(Tamanho: Tamanho) {
    return await this.httpClient.post(this.url, JSON.stringify(Tamanho), this.httpHeaders).toPromise();
  }

  async update(Tamanho: Tamanho) {
    return await this.httpClient.put(this.url, JSON.stringify(Tamanho), this.httpHeaders).toPromise();
  }

  async delete(idTamanho: number) {
    return await this.httpClient.delete(this.url + "/" + idTamanho).toPromise();
  }
}
