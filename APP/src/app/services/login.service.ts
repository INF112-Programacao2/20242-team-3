import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class LoginService {

  httpHeaders = {
    headers: new HttpHeaders({ 'Content-Type': 'application/json' })
  }

  url: string = 'http://localhost:3000/armor/login/';

  constructor(private httpClient: HttpClient) { }

  async login(email: string, senha: string) {
    return await this.httpClient.get(this.url + "email/" + email + "/senha/" + senha).toPromise();
  }
}
