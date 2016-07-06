//
//  Estrutura.hpp
//  Trabalho ED2
//
//  Created by Yan Ferreira on 6/25/16.
//  Copyright © 2016 Yan Ferreira. All rights reserved.
//

#ifndef Estrutura_hpp
#define Estrutura_hpp
#pragma once

#include "Helper.hpp"

#endif /* Estrutura_hpp */

class Estrutura{

public:

    //Instância do helper
    Helper helper;
    int num_insercoes;

    virtual void insere(std::string insert_string) = 0;
    virtual bool busca(std::string search_string) = 0;
    virtual void imprime(std::string file_name) = 0;
    virtual void imprimeAvaliacoes() = 0;

    virtual ~Estrutura() {};
};
