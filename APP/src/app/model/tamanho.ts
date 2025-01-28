enum TipoProduto {
    BERMUDA, FAIXA, KIMONO, RASH_GUARD
}

export class Tamanho {
    idTamanho: number;
    tipoProduto: TipoProduto | null;
    nome: string;

    constructor() {
        this.idTamanho = 0;
        this.tipoProduto = null;
        this.nome = "";
    }
}