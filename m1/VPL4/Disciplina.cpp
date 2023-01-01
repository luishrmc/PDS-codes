#include "Disciplina.hpp"
#include <algorithm>
#include <iostream>

Disciplina::Disciplina(string codigo, string nome) {
  _codigo = codigo;
  _nome = nome;
}

void Disciplina::inserir_alocacao(string dia, string horario, string sala) {
  Alocacao aux(dia, horario, sala);
  this->alocacao.push_back(aux);
}

void Disciplina::remover_alocacao(string horario) {
  int index = 0;
  for (Alocacao &alc : this->alocacao) {
    if (alc._horario == horario) {
      this->alocacao.erase(this->alocacao.begin() + index);
    }
    index += 1;
  }
}

bool sorting(Alocacao alc1, Alocacao alc2) {
  return (alc1._horario < alc2._horario);
}

void Disciplina::imprimir_alocacao() {

  std::sort(this->alocacao.begin(), this->alocacao.end(), sorting);

  for (Alocacao alc : this->alocacao) {
    std::cout << this->_codigo << ' ' << this->_nome << ' ';
    alc.imprimir_dados();
  }
}
