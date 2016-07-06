//
//  Arvore_AVL.cpp
//  Trabalho ED2
//
//  Created by Yan Ferreira on 6/30/16.
//  Copyright © 2016 Yan Ferreira. All rights reserved.
//

#include "Arvore_AVL.hpp"

void Arvore_AVL::desalocaNos(No_AVL *raiz){
    if(raiz == NULL)
        return;

    desalocaNos(raiz->getEsq());
    desalocaNos(raiz->getDir());

    delete raiz;
}

bool Arvore_AVL::busca(string search_string){
    return auxBusca(root, search_string);
}

bool Arvore_AVL::auxBusca(No_AVL * raiz, string search_string){
    if (raiz == NULL)
        return false;

    if(raiz->getPalavra() == search_string)
        return true;

    return (search_string < raiz->getPalavra()) ?
        auxBusca(raiz->getEsq(), search_string) : auxBusca(raiz->getDir(), search_string);
}

void Arvore_AVL::insere(string insert_string){
    root = auxInsere(root, insert_string);
}

No_AVL * Arvore_AVL::auxInsere(No_AVL * raiz, string insert_string){
    //Primeiro critério de parada
    if (raiz == NULL){
        No_AVL * newNo = new No_AVL();
        newNo->setPalavra(insert_string);

        num_insercoes ++;

        return newNo;
    }

    //Chamada da recursão
    if(insert_string < raiz->getPalavra()){
        raiz->setEsq(auxInsere(raiz->getEsq(), insert_string));
    } else if (insert_string > raiz->getPalavra()){
        raiz->setDir(auxInsere(raiz->getDir(), insert_string));
    //Segundo critério de parada
    } else {
        return raiz;
    }

    //Atualiza os fatores de balanceamento
    raiz->atualizaFatorBalanceamento();

    //Realiza as operações de balanceamento, se necessário
    if(raiz->getFatorBalanceamento() == 2){
        raiz = corrigeFatorBalanceamentoPositivo(raiz);
    } else if(raiz->getFatorBalanceamento() == -2){
        raiz = corrigeFatorBalanceamentoNegativo(raiz);
    }

    return raiz;
}

void Arvore_AVL::imprime(string file_name)
{
    ofstream file (file_name.c_str());
    imprimeAuxiliar(root, file);
    file.close();
}

void Arvore_AVL::imprimeAuxiliar(No_AVL * raiz, ofstream &file)
{
    if(raiz != NULL){
        imprimeAuxiliar(raiz->getEsq(), file);
        file << raiz->getPalavra() + '\n';
        imprimeAuxiliar(raiz->getDir(), file);
    }
}

void Arvore_AVL::imprimeAvaliacoes()
{
    cout << "Houveram " << num_insercoes << " inserções" << endl;
    cout << "A altura da árvore é: " << getAlturaArvore(root) << endl;
}

int Arvore_AVL::getAlturaArvore(No_AVL *raiz)
{
    if(raiz == NULL)
        return -1;

    return 1 + max(getAlturaArvore(raiz->getEsq()), getAlturaArvore(raiz->getDir()));
}

//Métodos de balanceamento
No_AVL * Arvore_AVL::corrigeFatorBalanceamentoNegativo(No_AVL *raiz){
    raiz->getDir()->atualizaFatorBalanceamento();
    if(raiz->getDir()->getFatorBalanceamento() > 0){
        raiz->setDir(rotacaoDireita(raiz->getDir()));
    }

    return rotacaoEsquerda(raiz);
}

No_AVL * Arvore_AVL::corrigeFatorBalanceamentoPositivo(No_AVL *raiz){
    raiz->getEsq()->atualizaFatorBalanceamento();
    if(raiz->getEsq()->getFatorBalanceamento() < 0){
        raiz->setEsq(rotacaoEsquerda(raiz->getEsq()));
    }

    return rotacaoDireita(raiz);
}

No_AVL * Arvore_AVL::rotacaoDireita(No_AVL *raiz){
    No_AVL * filhoEsq = raiz->getEsq();
    raiz->setEsq(filhoEsq->getDir());
    filhoEsq->setDir(raiz);

    return filhoEsq;
}

No_AVL * Arvore_AVL::rotacaoEsquerda(No_AVL *raiz){
    No_AVL * filhoDir = raiz->getDir();
    raiz->setDir(filhoDir->getEsq());
    filhoDir->setEsq(raiz);

    return filhoDir;
}
