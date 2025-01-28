enum Sexo {
    MASCULINO, FEMININO
}

export class Pessoa {
    idPessoa: number;
    nome: string;
    nascimento: string;
    telefone: string;
    cpf: string;
    idade: number;
    sexo: Sexo | null;

    constructor() {
        this.idPessoa = 0;
        this.nome = "";
        this.nascimento = "";
        this.telefone = "";
        this.cpf = "";
        this.idade = 0;
        this.sexo = null;
    }
}
