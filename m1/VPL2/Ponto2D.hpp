#ifndef PONTO2D_H
#define PONTO2D_H

#include <cmath>

struct Ponto2D {
  double _x, _y; // Atributos
  // Construtor
  Ponto2D(double _x = 0, double _y = 0);     // Cabeçalho
  double calcular_distancia(Ponto2D *ponto); // Cabeçalho
};

#endif
