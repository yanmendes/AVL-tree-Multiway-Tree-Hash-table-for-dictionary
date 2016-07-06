//
//  TabelaASCIIUTF8.hpp
//  Trabalho ED2
//
//  Created by Yan Ferreira on 6/15/16.
//  Copyright © 2016 Yan Ferreira. All rights reserved.
//

#ifndef Helper_hpp
#define Helper_hpp

#include <string>
#include <iostream>
#include <locale>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <list>
#include <cstdlib>
#include <dirent.h>
#include <cwchar>
#include <algorithm>
#include <time.h>
#include <cstring>

//Classe curinga que possui todos os includes e códigos auxiliares

class Helper{
private:
    //Vetor que guarda a tabela ASCII reduzida
    int portAsc[255];
    bool isPrimo(int val, int divisor);

public:
    Helper();
    int TAM_ALFABETO;
    int getCodeByAsc(char character) {return portAsc[(int) character];};
    unsigned char getAscByCode(int index);
    int getNextPrimo(int val);
    int getPreviousPrimo(int val);
    std::string normalize(std::string str);
    ~Helper() {};
};

#endif /* TabelaASCIIUTF8_hpp */
