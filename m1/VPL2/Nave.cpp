#include <iostream>
#include "Nave.hpp"
#include "Ponto2D.hpp"

Nave::Nave(Ponto2D posicao, double forca, double energia){
    _posicao = posicao;
    _forca = forca;
    _energia = energia;
}

void Nave::mover(double dx, double dy){
    this->_posicao._x += dx;
    this->_posicao._y += dy;
}

double Nave::calcular_distancia(Nave* nave){
    return this->_posicao.calcular_distancia(&nave->_posicao);
    
}

Nave* Nave::determinar_nave_mais_proxima(Nave** naves, int n){
    double aux = 999.9;
    Nave* result;
    for (int i=0; i<n; i++){
        double dist = this->calcular_distancia(*(naves+i));

        if (dist < aux && dist != 0){
            aux = dist;
            result = *(naves + i);
        }
    }
    return result;
}

void Nave::atacar(Nave** naves, int n){
    Nave* NME = this->determinar_nave_mais_proxima(naves,n);
    double distance = this->_posicao.calcular_distancia(&NME->_posicao);

    double attack = (100/distance)*this->_forca;

    if (attack > 30){
        attack = 30;
    }

    NME->_energia -= attack;

    if (NME->_energia <= 50){
        std::cout << "Energia baixa!" << std::endl;
    }
}

void Nave::imprimir_status(){
    std::cout << this->_posicao._x << ' ' << this->_posicao._y << ' ' << this->_energia << std::endl;
}