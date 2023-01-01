#include "Processo.hpp"
#include <iostream>

Processo::Processo(int id, string nome, int prioridade) {
  _id = id;
  _prioridade = prioridade;
  _nome = nome;
}

void Processo::imprimir_dados() {
  cout << this->_id << ' ' << this->_nome << ' ' << this->_prioridade << endl;
}
