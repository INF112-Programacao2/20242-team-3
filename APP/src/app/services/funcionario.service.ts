import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Injectable } from '@angular/core';
import { Funcionario } from '../model/funcionario';

@Injectable({
  providedIn: 'root'
})
export class FuncionarioService {
  httpHeaders = {
    headers: new HttpHeaders({ 'Content-Type': 'application/json' })
  }

  url: string = 'http://localhost:3000/armor/funcionario/';

  constructor(private httpClient: HttpClient) { }

  async getById(idFuncionario: number) {
    return await this.httpClient.get(this.url + "" + idFuncionario).toPromise();
  }

  async getAll() {
    return await this.httpClient.get(this.url).toPromise();
  }

  async insert(funcionario: Funcionario) {
    return await this.httpClient.post(this.url, JSON.stringify(funcionario), this.httpHeaders).toPromise();
  }

  async update(funcionario: Funcionario) {
    return await this.httpClient.put(this.url, JSON.stringify(funcionario), this.httpHeaders).toPromise();
  }

  async delete(idFuncionario: number) {
    return await this.httpClient.delete(this.url + "" + idFuncionario).toPromise();
  }

  saveSession(idPessoa: number) {
    localStorage.setItem("currentFuncionarioId", JSON.stringify(idPessoa));
  }

  recoverSession() {
    return Number(localStorage.getItem("currentFuncionarioId"));
  }

  isSessionActive() {
    const idFuncionario = Number(localStorage.getItem("currentFuncionarioId"));
    return !isNaN(idFuncionario) && idFuncionario > 0;
  }
}
