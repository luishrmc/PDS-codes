#include "celular.hpp"

int Celular::codigo = 1;

Celular::Celular(string modelo, string fabricante, int armazenamento,
                 int memoria, double peso, string cor, int qtd, float valor) {
  _modelo = modelo;
  _fabricante = fabricante;
  _armazenamento = armazenamento;
  _memoria = memoria;
  _peso = peso;
  _cor = cor;
  _qtd = qtd;
  _valor = valor;
  _codigo = codigo;

  codigo++;
}
/*Método para implementação de um operador
(podendo ser quaisquer outros operadores) nos objetos em questão.
Dado que, por ser um TAD, não há lógica de operação definida como nos Tipos
Primitivos*/

bool Celular::operator<(const Celular &other) {

  if (this->_fabricante < other._fabricante) {
    return true;
  }

  if (this->_fabricante == other._fabricante) {
    if (this->_modelo < other._modelo) {
      return true;
    }
  }

  return false;
}
