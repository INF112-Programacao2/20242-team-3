import { Cliente } from "./cliente";
import { Produto } from "./produto";

enum Satisfacao {
    MUITO_RUIM, RUIM, REGULAR, BOM, MUITO_BOM
}

enum Ajuste {
    JUSTO, LEVEMENTE_JUSTO, BOM, LEVEMENTE_FOLGADO, FOLGADO
}

export class Venda {
    idVenda: number;
    cpf: string;
    cliente: Cliente | null;

    SKU: string;
    produto: Produto | null;

    dataVenda: string;
    satisfacao: Satisfacao | null;
    ajuste: Ajuste | null;

    constructor() {
        this.idVenda = 0;
        this.cpf = "";
        this.cliente = null;
        this.SKU = "";
        this.produto = null;
        this.dataVenda = "";
        this.satisfacao = null;
        this.ajuste = null;
    }
}
