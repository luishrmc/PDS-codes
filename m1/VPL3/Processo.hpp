#ifndef PROCESSO_H
#define PROCESSO_H
#include <string>
using namespace std;

struct Processo{
    int _id, _prioridade; string _nome; //Atributos

    Processo(int id, string nome, int prioridade); //Constructor
    void imprimir_dados();

    Processo* next = nullptr;
    Processo* previous = nullptr;
};

#endif
