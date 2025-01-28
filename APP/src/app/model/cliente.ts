import { Pessoa } from "./pessoa";

export class Cliente extends Pessoa {
    envergadura: number;
    peso: number;
    altura: number;
    torax: number;
    cintura: number;

    constructor() {
        super();
        this.envergadura = 0;
        this.peso = 0;
        this.altura = 0;
        this.torax = 0;
        this.cintura = 0;
    }
}
