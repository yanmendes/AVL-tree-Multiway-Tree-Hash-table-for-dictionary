//
//  Arvore_AVL.hpp
//  Trabalho ED2
//
//  Created by Yan Ferreira on 6/30/16.
//  Copyright © 2016 Yan Ferreira. All rights reserved.
//

#ifndef Arvore_AVL_hpp
#define Arvore_AVL_hpp

#include "Estrutura.hpp"
#include "No_AVL.hpp"

class Arvore_AVL: public Estrutura{
private:
    //Atributo
    No_AVL * root;

    //Métodos recursivos
    void desalocaNos(No_AVL * raiz);
    bool auxBusca(No_AVL * raiz, string search_string);
    No_AVL * auxInsere(No_AVL * raiz, string insert_string);
    void imprimeAuxiliar(No_AVL * raiz, ofstream &file);
    int getAlturaArvore(No_AVL * raiz);

    //Operações AVL
    No_AVL * corrigeFatorBalanceamentoNegativo(No_AVL * raiz);
    No_AVL * corrigeFatorBalanceamentoPositivo(No_AVL * raiz);
    No_AVL * rotacaoEsquerda(No_AVL * raiz);
    No_AVL * rotacaoDireita(No_AVL * raiz);
public:
    //Métodos
    //Construtor
    Arvore_AVL() {root = NULL; num_insercoes = 0;};

    //@Override
    void insere(string insert_string);
    bool busca(string search_string);
    void imprime(string file_name);
    void imprimeAvaliacoes();

    //Destrutor
    ~Arvore_AVL() {desalocaNos(root);};
};

#endif /* Arvore_AVL_hpp */
