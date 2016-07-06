//
//  No_Multiway.hpp
//  Trabalho ED2
//
//  Created by Yan Ferreira on 6/10/16.
//  Copyright © 2016 Yan Ferreira. All rights reserved.
//

#ifndef No_Multiway_hpp
#define No_Multiway_hpp

class No_Multiway{
public:
    //Atributos:
    
    //O vetor used possui o tamanho do nosso alfabeto reduzido e a i-ésima posição deste corresponde à i-ésima letra desse alfabeto (portAsc do Helper)
    bool * used;
    
    //Este vetor também possui o tamanho do alfabeto e é uma flag utilizada na busca, já que, por exemplo, este a palavra cachorro mas não existe a palavra cac. Este vetor só é utilizado para marcar se a última letra da busca é, de fato, a última letra da palavra inserida.
    //Para não fazer alocação de memória desencessária, aloca-se o vetor à medida que for necessário na inserção
    bool * lastLetter;
    
    //Para não fazer alocação de memória desencessária, aloca-se os filhos à medida que for necessário na inserção
    No_Multiway ** filhos;
    
    //Métodos:
    
    //Construtor
    No_Multiway(int TAM_ALFABETO);
    
    //Destrutor
    ~No_Multiway();
    
    //Aloca o vetor lastLetter e seta todas as posições como falsa
    void initLastLetter(int TAM_ALFABETO);
    
    //Aloca o vetor filhos e chama o construtor de No_Multiway
    void initFilhos(int TAM_ALFABETO);
};

#endif /* No_Multiway_hpp */
