//
//  Reader.hpp
//  Trabalho ED2
//
//  Created by Yan Ferreira on 6/26/16.
//  Copyright © 2016 Yan Ferreira. All rights reserved.
//

#ifndef Reader_hpp
#define Reader_hpp

#include "Arvore_Multiway.hpp"
#include "Arvore_AVL.hpp"
#include "Tabela_Hash.hpp"

class Reader{
private:
    //Atributos
    Helper helper;

    //Métodos
    std::list<string> getFilesInDirectory(string directory);
    void insereDicionario(Estrutura * estrutura, ifstream &file);
    void buscaDicionario(Estrutura * corretor, Estrutura * estrutura, ifstream &file);
public:
    Reader() {};
    ~Reader() {};
    void inserePorDiretorio(Estrutura * estrutura, string directory);
    void fazBuscaOrtograficaPorDiretorio(Estrutura * corretor, Estrutura * estrutura, string directory);
    int getNumRegistros(string directory);
};

#endif /* Reader_hpp */
