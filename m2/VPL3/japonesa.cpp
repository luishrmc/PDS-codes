#include "japonesa.hpp"

string Japonesa::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da comida
   * japonesa.
   *
   * Exemplos:
   * 1X Comida japonesa - Combo 1, 4 sushis, 5 temakis e 6 hots.
   * 1X Comida japonesa - Combo 2, 5 sushis, 6 temakis e 8 hots.
   */
  string descr;
  descr += to_string(this->m_qtd) + "X Comida japonesa - " + this->_combinado + ", ";

  if(this->_sushi == 1){ //Plural e Singular
    descr += "1 sushi, ";
  }
  else {
    descr += to_string(this->_sushi) + " sushis, ";
  }

  if(this->_temaki == 1){
    descr += "1 temaki, ";
  }
  else {
    descr += to_string(this->_temaki) + " temakis e ";
  }

  if(this->_hots == 1){
    descr += "1 hot.";
  }
  else {
    descr += to_string(this->_hots) + " hots.";
  }

  return descr;
}

Japonesa::Japonesa(const string& combinado,
                   int sushis,
                   int temakis,
                   int hots,
                   int qtd,
                   float valor_unitario) {
  this->_combinado = combinado;
  this->_sushi = sushis;
  this->_temaki = temakis;
  this->_hots = hots;
  this->m_qtd = qtd;
  this->m_valor_unitario = valor_unitario; 
}