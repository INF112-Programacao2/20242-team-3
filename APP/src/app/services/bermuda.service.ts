import { Injectable } from '@angular/core';
import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Bermuda } from '../model/bermuda';

@Injectable({
  providedIn: 'root'
})
export class BermudaService {

  httpHeaders = {
    headers: new HttpHeaders({ 'Content-Type': 'application/json' })
  }

  url: string = 'http://localhost:3000/armor/produtos/bermuda/';

  constructor(private httpClient: HttpClient) { }

  async getById(idBermuda: number) {
    return await this.httpClient.get(this.url + "" + idBermuda).toPromise();
  }

  async getAll() {
    return await this.httpClient.get(this.url).toPromise();
  }

  async insert(bermuda: Bermuda) {
    return await this.httpClient.post(this.url, JSON.stringify(bermuda), this.httpHeaders).toPromise();
  }

  async update(bermuda: Bermuda) {
    return await this.httpClient.put(this.url, JSON.stringify(bermuda), this.httpHeaders).toPromise();
  }

  async delete(idBermuda: number) {
    return await this.httpClient.delete(this.url + "" + idBermuda).toPromise();
  }
}
