#ifndef NAVE_H
#define NAVE_H
#include "Ponto2D.hpp"

struct Nave {
  Ponto2D _posicao; // Atributos
  double _forca, _energia;

  // Construtor
  Nave(Ponto2D _posicao, double _forca = 1, double _energia = 100);

  void mover(double dx, double dy);

  double calcular_distancia(Nave *nave);

  Nave *determinar_nave_mais_proxima(Nave **naves, int n);

  void atacar(Nave **naves, int n);

  void imprimir_status();
};

#endif
