#ifndef ALOCACAO_H
#define ALOCACAO_H
#include <string>
using std::string;

struct Alocacao {
  string _dia, _horario, _sala;                      // Atributos
  Alocacao(string dia, string horario, string sala); // Constructor
  void imprimir_dados();
};

#endif
