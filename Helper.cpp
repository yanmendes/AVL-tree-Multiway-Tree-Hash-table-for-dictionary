//
//  Helper.cpp
//  Trabalho ED2
//
//  Created by Yan Ferreira on 6/17/16.
//  Copyright © 2016 Yan Ferreira. All rights reserved.
//

#include "Helper.hpp"

using namespace std;

Helper::Helper()
{
    char c[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M','N' ,'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    for (int i=0; i<255; i++){
        portAsc[i] = -1;
    }

    for(int i=0; i<=25; i++){
        portAsc[(int) tolower(c[i])] = i;
        portAsc[(int) c[i]] = i;
    }

    TAM_ALFABETO = 26;
}

//Função que pega o próximo primo dado um número
int Helper::getNextPrimo(int val)
{
    //Verifica se par, se for pega seu sucessor
    val = (val % 2 == 0) ? val + 1 : val;
    int i;

    //Propriedade de números compostos: C é composto <-> existe um primo p <= sqrt(C) / p | C.
    for(i = val; i < val * 2 && !isPrimo(i, sqrt(i)); i += 2);

    return i;
}

//Função que pega o primo anterior dado um número
int Helper::getPreviousPrimo(int val)
{
    //Verifica se par, se for pega seu antecessor
    val = (val % 2 == 0) ? val - 1 : val;
    int i;

    //Propriedade de números compostos: C é composto <-> existe um primo p <= sqrt(C) / p | C.
    for(i = val; i > 997 && !isPrimo(i, sqrt(i)); i -= 2);

    return i;
}

bool Helper::isPrimo(int val, int divisor){
    if(divisor == 2)
        return true;
    if(val % divisor == 0)
        return false;
    return isPrimo(val, --divisor);
}

unsigned char Helper::getAscByCode(int index){
    int i;

    for(i = 0; i < 255 && index != portAsc[i]; i++);

    return (unsigned char) i;
}

string Helper::normalize(string str){
    //tolower
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    //remove pontuação
    str.erase(remove_if(str.begin(), str.end(), ::ispunct), str.end());
    //remove números
    str.erase(remove_if(str.begin(), str.end(), ::isdigit), str.end());

    return str;
}
