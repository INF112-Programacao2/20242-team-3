import { Pessoa } from "./pessoa";

export class Funcionario extends Pessoa {
    email: string;
    emailDecrypted: string;
    senha: string;

    constructor() {
        super();
        this.email = "";
        this.emailDecrypted = "";
        this.senha = "";
    }
}