//
//  Reader.cpp
//  Trabalho ED2
//
//  Created by Yan Ferreira on 6/26/16.
//  Copyright © 2016 Yan Ferreira. All rights reserved.
//

#include "Reader.hpp"

std::list<string> Reader::getFilesInDirectory(string directory)
{
    std::list<string> files;

    DIR * diretorio;
    struct dirent * entry;

    if((diretorio = opendir(directory.c_str()))){
        while((entry = readdir(diretorio))){
            if (string(entry->d_name).find(".txt") != string::npos || string(entry->d_name).find(".rtf") != string::npos) {
                files.push_front(directory + entry->d_name);
            }
        }
        closedir(diretorio);
    }

    return files;
}

void Reader::inserePorDiretorio(Estrutura *estrutura, string directory)
{
    std::list<string> files = getFilesInDirectory(directory);

    while(!files.empty()){
        string file_name = files.front();

        ifstream file (file_name.c_str());

        insereDicionario(estrutura, file);

        file.close();

        files.pop_front();
    }
}

void Reader::insereDicionario(Estrutura * estrutura, ifstream &file)
{
    string linha;

    while(file >> linha){
        transform(linha.begin(), linha.end(), linha.begin(), ::tolower);
        estrutura->insere(linha.substr(0, linha.find('/', 0)));
    }
}

int Reader::getNumRegistros(string directory)
{
    std::list<string> files = getFilesInDirectory(directory);
    int count = 0;

    while(!files.empty()){
        string file_name = files.front();

        ifstream file (file_name.c_str());

        string linha;
        while (file >>linha){
            count++;
        }

        file.close();

        files.pop_front();
    }

    return count;
}

void Reader::fazBuscaOrtograficaPorDiretorio(Estrutura * corretor, Estrutura * estrutura, string directory)
{
    std::list<string> files = getFilesInDirectory(directory);

    while(!files.empty()){
        string file_name = files.front();

        ifstream file (file_name.c_str());

        buscaDicionario(corretor, estrutura, file);

        file.close();

        files.pop_front();
    }

}

void Reader::buscaDicionario(Estrutura * corretor, Estrutura * estrutura, ifstream &file)
{
    string linha;

    while(file >> linha){
        if(linha == "")
            continue;

        string palavra = helper.normalize(linha);

        if(palavra == "" && !estrutura->busca(palavra)){
            corretor->insere(palavra);
        }
    }
}
