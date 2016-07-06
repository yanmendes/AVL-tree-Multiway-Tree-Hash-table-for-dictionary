//
//  Arvore_Multiway.cpp
//  Trabalho ED2
//
//  Created by Yan Ferreira on 6/16/16.
//  Copyright © 2016 Yan Ferreira. All rights reserved.
//

#include "Arvore_Multiway.hpp"

using namespace std;

bool Arvore_Multiway::busca(string search_string)
{
    int i, length = (int) search_string.length();
    No_Multiway * aux = root;
    bool error = false;

    //Percorre até a penúltima letra da palavra, descendo para o filho na posição adequada.
    //Critérios de parada:
    //  (1) Percorrer a palavra até a penúltima letra
    //  (2) Caracter inválido
    //  (3) 3.1 - Nó nulo (não existe filho instanciado) ou 3.2 - Letra não utilizada na inserção

    //          (1)
    for(i = 0; i < length - 1; i++){
        int position = helper.getCodeByAsc(search_string.at(i));

        // (2)
        if(position == -1){
            error = true;
            break;
        }

        // (3)
        if(aux == NULL || !aux->used[position]){
            break;
        }

        aux = aux->filhos[position];
    }

    if(error){
        return false;
    }

    return
    i == length - 1
    && aux != NULL
    && helper.getCodeByAsc(search_string.at(i)) != -1
    && aux->lastLetter[helper.getCodeByAsc(search_string.at(i))];
}

void Arvore_Multiway::insere(string insert_string)
{
    int i, length = (int) insert_string.length();
    No_Multiway * aux = root;

    bool error = false;

    //Percorre até a penúltima letra da palavra, descendo para o filho na posição adequada.
    //Critérios de parada:
    //  (1) Percorrer a palavra até a penúltima letra
    //  (2) Caracter inválido

    //          (1)
    for(i = 0; i < length - 1; i++){
        int position = helper.getCodeByAsc(insert_string.at(i));

        //(2)
        if(position == -1){
            error = true;
            break;
        }

        if(aux->filhos == NULL) {
            aux->initFilhos(helper.TAM_ALFABETO);
        }

        aux->used[position] = true;

        aux = aux->filhos[position];
    }

    if(error){
        return;
    }

    //Marca a última letra como utilizada
    aux->used[helper.getCodeByAsc(insert_string.at(i))] = true;

    if(aux->lastLetter == NULL){
        aux->initLastLetter(helper.TAM_ALFABETO);
    }

    //Marca a flag de última letra
    aux->lastLetter[helper.getCodeByAsc(insert_string.at(i))] = true;

    num_insercoes++;
}

void Arvore_Multiway::imprime(string file_name)
{
    ofstream file (file_name.c_str());
    imprimeAuxiliar("", root, file);
    file.close();
}

void Arvore_Multiway::imprimeAuxiliar(string palavra, No_Multiway * raiz, ofstream &file)
{
    for(int i = 0; i < helper.TAM_ALFABETO; i++){
        if(raiz->used[i]){
            string aux_string = palavra;
            aux_string.push_back(helper.getAscByCode(i));
            if(raiz->lastLetter != NULL && raiz->lastLetter[i]){
                //strtolower
                std::transform(aux_string.begin(), aux_string.end(), aux_string.begin(), ::tolower);
                file << aux_string + "\n";
            }

            if(raiz->filhos != NULL){
                imprimeAuxiliar(aux_string, raiz->filhos[i], file);
            }
        }
    }
}

Arvore_Multiway::~Arvore_Multiway()
{
    //Desaloca todos os filhos e raiz
    desalocaNos(root);
}

void Arvore_Multiway::desalocaNos(No_Multiway *raiz)
{
    if(raiz == NULL){
        return;
    }

    for(int i = 0; i < helper.TAM_ALFABETO; i++){
        if(raiz->filhos != NULL)
            desalocaNos(raiz->filhos[i]);
    }

    raiz->~No_Multiway();
}

