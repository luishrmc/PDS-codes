#ifndef QUADROALOCACAO_H
#define QUADROALOCACAO_H
#include "Disciplina.hpp"
#include <map>
#include <vector>
using std::vector;

struct QuadroAlocacao {

  std::map<string, Disciplina> quadroAloc;

  void inserir_alocacao(string codigo, string nome, string dia, string horario,
                        string sala);
  void remover_alocacao_disciplina(string codigo, string horario);
  vector<Disciplina> recuperar_disciplinas_mais_ofertadas();
  void imprimir_alocacao_completa();
};

#endif
