//
//  Registro_Hash.hpp
//  Trabalho ED2
//
//  Created by Yan Ferreira on 6/24/16.
//  Copyright © 2016 Yan Ferreira. All rights reserved.
//

#ifndef Registro_Hash_hpp
#define Registro_Hash_hpp

#include "Helper.hpp"

using namespace std;

class Registro_Hash{
private:
    //Atributos
    unsigned long int key;
    string palavra;

public:
    //Atributo de avaliação
    bool hasColided;

    //Métodos
    Registro_Hash() {key = 0; palavra = ""; hasColided = false;};

    void setKey(unsigned long int key) {this->key = key;};
    void setPalavra(string palavra) {this->palavra = palavra;};

    unsigned long int getKey() {return key;};
    string getPalavra() {return palavra;};

    ~Registro_Hash() {};
};

#endif /* Registro_Hash_hpp */
