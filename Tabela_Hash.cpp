//
//  Tabela_Hash.cpp
//  Trabalho ED2
//
//  Created by Yan Ferreira on 6/24/16.
//  Copyright © 2016 Yan Ferreira. All rights reserved.
//

#include "Tabela_Hash.hpp"

Tabela_Hash::Tabela_Hash(int size, int hashFunction)
{
    //Aloca 10% a mais posições para buscar em O(10)
    this->size = size * 1.1;

    //Escolha da função de hash a ser utilizada
    switch (hashFunction) {
        case 1:
            this->current_hash_function = &Tabela_Hash::hashDjb2;
            break;
        case 2:
            this->current_hash_function = &Tabela_Hash::hashLogico;
            break;
        default:
            this->current_hash_function = &Tabela_Hash::hashNextPrimo;
            break;
    }

    this->table = new Registro_Hash[this->size];

    //Inicializando as variáveis auxiliares
    this->multiplicador_chave = helper.getNextPrimo(helper.TAM_ALFABETO);
    this->nextPrimo = helper.getNextPrimo(this->size);
    this->previousPrimo = helper.getPreviousPrimo(this->size);
    this->num_colisoes = 0;
    this->num_insercoes = 0;
}

bool Tabela_Hash::busca(string search_string)
{
    unsigned long int key;

    //Cálculo da chave e posição a partir da string a partir da função de hash
    unsigned int pos = (this->*current_hash_function)(search_string, &key);

    unsigned long int i;
    unsigned long int passoRehash = rehashFunction(key);
    unsigned long int capacity = (size * passoRehash);

    for(i = 0; i < capacity && table[(pos + i) % size].getKey() != 0; i += passoRehash){
        if(table[(pos + i) % size].getKey() == key
           && !strcmp(table[(pos + i) % size].getPalavra().c_str(), search_string.c_str()))
            break;
    }

    return
        i < (size * passoRehash)
        && table[(pos + i) % size].getKey() == key
        && (!strcmp(table[(pos + i) % size].getPalavra().c_str(), search_string.c_str()));
}

void Tabela_Hash::insere(string insert_string)
{
    unsigned long int key;

    //Cálculo da chave e posição a partir da string a partir da função de hash
    unsigned int pos = (this->*current_hash_function)(insert_string, &key);

    unsigned long int i;
    unsigned long int passoRehash = rehashFunction(key);
    unsigned long int capacity = (size * passoRehash);

    //Cálculo de índices de colisão
    if(table[pos].getKey() != 0 && strcmp(table[pos].getPalavra().c_str(), insert_string.c_str()))
        table[pos].hasColided = true;

    for(i = 0; i < capacity && table[(pos + i) % size].getKey() != 0; i += passoRehash){
        if(table[(pos + i) % size].getKey() == key
           && !strcmp(table[(pos + i) % size].getPalavra().c_str(), insert_string.c_str()))
            return;
    }

    num_colisoes += (bool) i;
    num_insercoes ++;
    table[(pos + i) % size].setKey(key);
    table[(pos + i) % size].setPalavra(insert_string);
}

void Tabela_Hash::imprime(string file_name)
{
    ofstream file (file_name.c_str());

    for(int i = 0; i < size; i ++){
        if(table[i].getKey() != 0)
            file << table[i].getPalavra() + "\n";
    }

    file.close();
}

unsigned int Tabela_Hash::hashDjb2(string palavra, unsigned long int * key)
{
    * key = 5381;
    for(int i = 0; i < (int) palavra.length(); i++)
        * key = (* key << 5) + * key + (int) palavra.at(i);

    return (* key % nextPrimo) % size;
}

unsigned int Tabela_Hash::hashLogico(string palavra, unsigned long int * key)
{
    * key = 0;
    for (int i = 0; i < (int) palavra.length(); i++)
        * key ^= (* key << 7) + (* key >> 2) + palavra[i];

    return  (* key % nextPrimo) % size;
}

unsigned int Tabela_Hash::hashNextPrimo(string palavra, unsigned long int * key)
{
    * key = 0;
    for (int i = 0; i < (int) palavra.length(); i++)
        * key = multiplicador_chave * (* key) + helper.getCodeByAsc(palavra.at(i));

    return (* key % nextPrimo) % size;
}

unsigned long int Tabela_Hash::rehashFunction(unsigned long int key)
{
    return (key % previousPrimo == 0) ? 1 : (key % previousPrimo);
}

int Tabela_Hash::getNumPastasColididas()
{
    int count = 0;
    for(int i = 0; i < size; i++)
        count += table[i].hasColided;
    return count;
};

void Tabela_Hash::imprimeAvaliacoes()
{
    cout << "Tamanho da tabela: " << size << endl;
    cout << "Houveram " << num_insercoes << " inserções" << endl;
    cout << "Houveram " << num_colisoes << " colisões" << endl;
    cout << "Percentual total de colisões: " << (float) num_colisoes/num_insercoes * 100 << endl;
    cout << "Distribuição média de colisões: " << (float) num_colisoes/getNumPastasColididas() << endl;
}
