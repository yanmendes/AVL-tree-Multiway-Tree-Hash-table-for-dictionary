//
//  No_AVL.hpp
//  Trabalho ED2
//
//  Created by Yan Ferreira on 6/30/16.
//  Copyright © 2016 Yan Ferreira. All rights reserved.
//

#ifndef No_AVL_hpp
#define No_AVL_hpp

#include "Helper.hpp"

using namespace std;

class No_AVL{
private:
    //Atributos:
    string palavra;
    No_AVL * esq;
    No_AVL * dir;
    int fatorBalanceamento;

    //Métodos
    int calculaAlturaSAE(No_AVL * raiz) {return (raiz == NULL) ? -1 : 1 + calculaAlturaSAE(raiz->esq);};
    int calculaAlturaSAD(No_AVL * raiz) {return (raiz == NULL) ? -1 : 1 + calculaAlturaSAD(raiz->dir);};

public:
    //Métodos:
    //Getters
    string getPalavra() {return this->palavra;};
    No_AVL * getEsq() {return this->esq;};
    No_AVL * getDir() {return this->dir;};
    int getFatorBalanceamento() {return this->fatorBalanceamento;};

    //Setters
    void setPalavra(string palavra) {this->palavra = palavra;};
    void setDir(No_AVL * node) {this->dir = node;};
    void setEsq(No_AVL * node) {this->esq = node;};

    //FB
    void atualizaFatorBalanceamento() {fatorBalanceamento = calculaAlturaSAE(this) - calculaAlturaSAD(this);};

    //Construtor
    No_AVL() {esq = NULL; dir = NULL; fatorBalanceamento = 0;};

    //Destrutor
    ~No_AVL() {};
};

#endif /* No_Multiway_hpp */
