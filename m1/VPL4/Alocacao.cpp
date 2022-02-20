#include "Alocacao.hpp"
#include <iostream>

Alocacao::Alocacao(string dia, string horario, string sala){
    _dia = dia;
    _horario = horario;
    _sala = sala;
}

void Alocacao::imprimir_dados(){
    std::cout << _dia << ' ' << _horario << ' ' << _sala << std::endl;
}