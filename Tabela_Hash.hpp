//
//  Tabela_Hash.hpp
//  Trabalho ED2
//
//  Created by Yan Ferreira on 6/24/16.
//  Copyright © 2016 Yan Ferreira. All rights reserved.
//

#ifndef Tabela_Hash_hpp
#define Tabela_Hash_hpp

#include "Registro_Hash.hpp"
#include "Estrutura.hpp"

class Tabela_Hash: public Estrutura{

private:
    //Atributos
    int size;

    //Ponteiro para a função de hash a ser escolhida no construtor
    typedef unsigned int (Tabela_Hash::*hash_function)(string palavra, unsigned long int * key);
    hash_function current_hash_function;

    //Tabela
    Registro_Hash * table;

    //Utilizado no hashNextPrimo. Inicializado no construtor
    int multiplicador_chave;

    //Utilizado para definir a posição na tabela a partir da função mod
    int nextPrimo;

    //Utilizado na função de rehash
    int previousPrimo;

    //Métodos de hash
    unsigned int hashDjb2(string palavra, unsigned long int * key);
    unsigned int hashLogico(string palavra, unsigned long int * key);
    unsigned int hashNextPrimo(string palavra, unsigned long int * key);

    //Rehash
    unsigned long int rehashFunction(unsigned long int key);

    //Variáveis de avaliação
    int num_colisoes;
    int getNumPastasColididas();

public:
    //Métodos:
    //Construtor
    Tabela_Hash(int size, int hashFunction);

    //@Override
    void insere(string insert_string);
    bool busca(string insert_string);
    void imprime(string file_name);
    void imprimeAvaliacoes();

    //Destrutor
    ~Tabela_Hash() {delete [] table;};
};

#endif /* Tabela_Hash_hpp */
