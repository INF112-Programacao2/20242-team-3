import { Produto } from "./produto";

enum Ajuste {
    ELASTICO, BOTAO, AMARRACAO
}

enum Comprimento {
    CURTO, MEDIO, LONGO
}

export class Bermuda extends Produto {
    ajuste: Ajuste | null;
    comprimento: Comprimento | null;

    constructor() {
        super();
        this.ajuste = null;
        this.comprimento = null;
    }
}
