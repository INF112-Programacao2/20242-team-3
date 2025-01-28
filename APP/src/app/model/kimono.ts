import { Produto } from "./produto";

enum Forma {
    TRADICIONAL, SLIM, ULTRASLIM
}

export class Kimono extends Produto {
    gramaturaTecido: number;
    encolhimento: number;
    forma: Forma | null;

    constructor() {
        super();
        this.gramaturaTecido = 0;
        this.encolhimento = 0;
        this.forma = null; 0
    }
}
