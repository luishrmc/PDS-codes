#include "venda.hpp"

#include <iomanip>

Venda::~Venda() {
  while(!this->m_pedidos.empty()) delete this->m_pedidos.front(), this->m_pedidos.pop_front();
  this->m_pedidos.clear();
}

void Venda::adicionaPedido(Pedido* p) {
  this->m_pedidos.push_back(p);
}

void Venda::imprimeRelatorio() const {
  string ender;
  float total = 0;
  int num = 1;
  for(auto it = this->m_pedidos.begin(); it != this->m_pedidos.end(); it++){
    cout << "Pedido " << num << endl;

    ender = (*it)->resumo();
    cout << "Endereco: " << ender << endl;

    total += (*it)->calculaTotal();
    num++;
  }
  cout << "Relatorio de Vendas" << endl;
  cout << "Total de vendas: R$ " << std::fixed << std::setprecision(2) << total << endl;
  cout << "Total de pedidos: " << this->m_pedidos.size();
}
