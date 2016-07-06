//
//  Arvore_Multiway.hpp
//  Trabalho ED2
//
//  Created by Yan Ferreira on 6/16/16.
//  Copyright © 2016 Yan Ferreira. All rights reserved.
//

#ifndef Arvore_Multiway_hpp
#define Arvore_Multiway_hpp

#include "No_Multiway.hpp"
#include "Estrutura.hpp"

#endif /* Arvore_Multiway_hpp */

//Classe com a estrutura de árvore

class Arvore_Multiway: public Estrutura{
private:
    //Atributos

    //Instância de No_Multiway que aponta é a raiz da árvore
    No_Multiway * root;

    //Método interno para destruir a árvore
    void desalocaNos(No_Multiway * raiz);

    //Método interno para impressão
    void imprimeAuxiliar(std::string palavra, No_Multiway * raiz, std::ofstream &file);
public:
    //Métodos
    //Construtor
    Arvore_Multiway() {root = new No_Multiway(helper.TAM_ALFABETO); num_insercoes = 0;};

    //@Override
    bool busca(std::string search_string);
    void insere(std::string insert_string);
    void imprime(std::string file_name);
    void imprimeAvaliacoes() {};

    //Destrutor
    ~Arvore_Multiway();
};
