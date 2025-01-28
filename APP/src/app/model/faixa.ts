import { Produto } from "./produto";

enum Espessura {
    CLASSICA, ROBUSTA
}

export class Faixa extends Produto {
    espessura: Espessura | null;

    constructor() {
        super();
        this.espessura = null;
    }
}
