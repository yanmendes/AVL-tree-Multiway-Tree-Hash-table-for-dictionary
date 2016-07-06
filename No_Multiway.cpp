//
//  No_Multiway.cpp
//  Trabalho ED2
//
//  Created by Yan Ferreira on 6/10/16.
//  Copyright © 2016 Yan Ferreira. All rights reserved.
//

#include "No_Multiway.hpp"
#include "Helper.hpp"

using namespace std;

No_Multiway::No_Multiway(int TAM_ALFABETO)
{
    filhos = NULL;
    lastLetter = NULL;

    used = new bool[TAM_ALFABETO];

    for(int i = 0; i < TAM_ALFABETO; i++){
        used[i] = false;
    }
}

No_Multiway::~No_Multiway()
{
    delete [] filhos;
    delete [] lastLetter;
}

void No_Multiway::initLastLetter(int TAM_ALFABETO)
{
    lastLetter = new bool[TAM_ALFABETO];
    for(int i = 0; i < TAM_ALFABETO; i++){
        lastLetter[i] = false;
    }
}

void No_Multiway::initFilhos(int TAM_ALFABETO)
{
    filhos = new No_Multiway * [TAM_ALFABETO];
    for(int i = 0; i < TAM_ALFABETO; i++){
        filhos[i] = new No_Multiway(TAM_ALFABETO);
    }
}
