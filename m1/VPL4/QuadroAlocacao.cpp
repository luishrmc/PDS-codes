#include "QuadroAlocacao.hpp"
#include <iostream>

void QuadroAlocacao::inserir_alocacao(string codigo, string nome, string dia,
                                      string horario, string sala) {

  for (auto it = this->quadroAloc.begin(); it != this->quadroAloc.end(); it++) {
    if (it->first == codigo) {
      it->second.inserir_alocacao(dia, horario, sala);
      return;
    }
  }

  Disciplina disc = {codigo, nome};
  disc.alocacao.push_back({dia, horario, sala});
  this->quadroAloc.insert(std::pair<string, Disciplina>(codigo, disc));
}

void QuadroAlocacao::remover_alocacao_disciplina(string codigo,
                                                 string horario) {

  for (auto it = this->quadroAloc.begin(); it != this->quadroAloc.end(); it++) {

    if (it->first == codigo) {
      it->second.remover_alocacao(horario);
    }
  }
}

vector<Disciplina> QuadroAlocacao::recuperar_disciplinas_mais_ofertadas() {
  vector<Disciplina> result;
  int aux = 0;

  for (auto it = this->quadroAloc.begin(); it != this->quadroAloc.end(); it++) {

    int quant = it->second.alocacao.size();

    /*for(Alocacao alc: it->second.alocacao){
        quant+=1;
    }*/

    if (aux < quant) {

      result.clear();
      result.push_back(it->second);
      aux = quant;

    } else if (aux == quant) {
      result.push_back(it->second);
    }
  }
  return result;
}

void QuadroAlocacao::imprimir_alocacao_completa() {
  for (auto it = this->quadroAloc.begin(); it != this->quadroAloc.end(); it++) {
    it->second.imprimir_alocacao();
  }
}
