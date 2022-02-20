#ifndef DISCIPLINA_H
#define DISCIPLINA_H
#include <vector>
#include "Alocacao.hpp"

struct Disciplina{
    string _codigo, _nome;
    std::vector<Alocacao> alocacao; //Atributos

    Disciplina(string codigo, string nome); //Constructor
    void inserir_alocacao(string dia, string horario, string sala);
    void remover_alocacao(string horario);
    void imprimir_alocacao();
};

#endif
