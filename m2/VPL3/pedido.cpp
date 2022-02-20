#include "pedido.hpp"


Pedido::~Pedido() {
  while(!this->m_produtos.empty()) delete this->m_produtos.front(), this->m_produtos.pop_front();
  this->m_produtos.clear();
}

void Pedido::setEndereco(const string& endereco) {
  this->m_endereco = endereco;
}

float Pedido::calculaTotal() const {
  float sum = 0;

  for(auto it = this->m_produtos.begin(); it != this->m_produtos.end(); it++){
    sum += (*it)->getValor() * (*it)->getQtd();
  }
  return sum;
}

void Pedido::adicionaProduto(Produto* p) {
  this->m_produtos.push_back(p);
}

string Pedido::resumo() const {
  
  for(auto it = this->m_produtos.begin(); it != this->m_produtos.end(); it++){
    cout << (*it)->descricao() << endl;
  }
  return this->m_endereco;
}