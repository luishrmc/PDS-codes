#include "pizza.hpp"

string Pizza::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da pizza.
   *
   * Exemplos:
   * 2X Pizza Calabresa, 4 pedacos e borda recheada.
   * 2X Pizza Calabresa, 4 pedacos sem borda recheada.
   */
  string descr;

  descr += to_string(this->m_qtd) + "X Pizza " + this->_sabor + ", " + to_string(this->_pedacos) + " pedacos ";

  if(this->_borda_recheada == true){
    descr += "e borda recheada.";
  }
  else {
    descr += "e sem borda recheada.";
  }
   
  return descr;
}

Pizza::Pizza(const string& sabor,
             int pedacos,
             bool borda_recheada,
             int qtd,
             float valor_unitario) {
  this->_sabor = sabor;
  this->_pedacos = pedacos;
  this->_borda_recheada = borda_recheada;
  this->m_qtd = qtd;
  this->m_valor_unitario = valor_unitario;
}