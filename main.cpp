//
//  main.cpp
//  Trabalho ED2
//
//  Created by Yan Ferreira on 6/10/16.
//  Copyright © 2016 Yan Ferreira. All rights reserved.
//

#include "Reader.hpp"
#include <fcntl.h>

using namespace std;

int main(int argc, const char * argv[]) {
    Estrutura * estrutura = NULL;
    Reader * reader = new Reader();
    Arvore_AVL * corretor = new Arvore_AVL();

    string diretorio_dicionario;
    string diretorio_textos;
    string arquivo_output;
    const char * struct_type;
    const char * hashFunction;

    bool production = false;

    if(production){
        diretorio_dicionario = argv[1];
        diretorio_textos = argv[2];
        arquivo_output = argv[3];
        struct_type = argv[4];
        hashFunction = argv[5];
    } else {
        diretorio_dicionario = "/home/yanmendes/Desktop/Instâncias\ ed2/Dicionarios_ingles/";
        diretorio_textos = "/home/yanmendes/Desktop/Instâncias\ ed2/Textos_ingles/TE7/";
        arquivo_output = "/home/yanmendes/Desktop/Instâncias\ ed2/output.txt";
        struct_type = "1";
        hashFunction = "2";
    }

    double tempo_total = 0;

    //Alocação
    cout << "Começando a alocação das estruturas..." << endl;
    clock_t tempo_inicial_alocacao = clock();

    switch (atoi(struct_type)){
        case 1:
        estrutura = new Arvore_AVL();
        break;

        case 2:
        estrutura = new Tabela_Hash(reader->getNumRegistros(diretorio_dicionario), atoi(hashFunction));
        break;

        case 3:
        estrutura = new Arvore_Multiway();
        break;
    }

    clock_t tempo_final_alocacao = clock();
    cout << "Finalizada a alocação... Tempo gasto: " << (double) (tempo_final_alocacao - tempo_inicial_alocacao) / 1000 <<
    "ms" << endl;

    tempo_total += (tempo_final_alocacao - tempo_inicial_alocacao) / 1000;

    //Inserção
    cout << "Começando a inserção..." << endl;
    clock_t tempo_inicial_insercao = clock();

    reader->inserePorDiretorio(estrutura, diretorio_dicionario);

    clock_t tempo_final_insercao = clock();
    cout << "Finalizada a inserção... Tempo gasto: " << (double) (tempo_final_insercao - tempo_inicial_insercao) / 1000  <<
    "ms" << endl;

    tempo_total += (tempo_final_insercao - tempo_inicial_insercao) / 1000;

    //Buscas
    cout << "Começando as buscas..." << endl;
    clock_t tempo_inicial_busca = clock();

    reader->fazBuscaOrtograficaPorDiretorio(corretor, estrutura, diretorio_textos);

    clock_t tempo_final_busca = clock();
    cout << "Finalizadas as buscas... Tempo gasto: " << (double) (tempo_final_busca - tempo_inicial_busca) / 1000  <<
    "ms" << endl;

    tempo_total += (tempo_final_busca - tempo_inicial_busca)  / 1000;

    //Impressão
    cout << "Começando a efetuar a impressão dos resultados..." << endl;
    clock_t tempo_inicial_impressao = clock();

    corretor->imprime(arquivo_output);

    estrutura->imprimeAvaliacoes();

    clock_t tempo_final_impressao = clock();
    cout << "Finalizada a impressão... Tempo gasto: " << (double) (tempo_final_impressao - tempo_inicial_impressao) / 1000  <<
    "ms" << endl;

    tempo_total += (tempo_final_impressao - tempo_inicial_impressao) / 1000;

    //Destrução
    cout << "Começando a destruir as estruturas..." << endl;
    clock_t tempo_inicial_destrutor = clock();

    corretor->~Arvore_AVL();
    estrutura->~Estrutura();

    clock_t tempo_final_destrutor = clock();
    cout << "Finalizada a destrução... Tempo gasto: " << (double) (tempo_final_destrutor - tempo_inicial_destrutor) / 1000 <<
    "ms" << endl;

    tempo_total += (tempo_final_destrutor - tempo_inicial_destrutor) / 1000;

    cout << "Tempo total gasto: " << tempo_total << "ms" << endl;

    return 0;
}
