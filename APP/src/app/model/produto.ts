import { Cor } from "./cor";
import { Marca } from "./marca";
import { Modelo } from "./modelo";
import { Tamanho } from "./tamanho";

enum Sexo {
    MASCULINO,
    FEMININO,
    UNISSEX
}

enum FaixaEtaria {
    ADULTO,
    INFANTIL,
    JUVENIL
}

export class Produto {
    idProduto: number;
    idMarca: number;
    marca: Marca | null;
    idModelo: number;
    modelo: Modelo | null;
    SKU: string;
    faixaEtaria: FaixaEtaria | null;
    idTamanho: number;
    tamanho: Tamanho | null;
    sexo: Sexo | null;
    idCor: number;
    cor: Cor | null;

    constructor() {
        this.idProduto = 0;
        this.idMarca = 0;
        this.marca = null;
        this.idModelo = 0;
        this.modelo = null;
        this.SKU = "";
        this.faixaEtaria = null;
        this.idTamanho = 0;
        this.tamanho = null;
        this.sexo = null;
        this.idCor = 0;
        this.cor = null;
    }
}
