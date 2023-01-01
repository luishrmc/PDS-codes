#include "venda.hpp"
#include <cctype>
#include <cmath>
#include <iomanip>
#include <iostream>

using std::cout;
using std::endl;

void Venda::adicionaCelular(const Celular &celular) {

  this->m_celulares.push_back(celular);
}

void Venda::ordena() { this->m_celulares.sort(); }

void Venda::recarregaEstoque(int cod, int qtd) {

  for (auto it = this->m_celulares.begin(); it != this->m_celulares.end();
       it++) {

    if (it->_codigo == cod) {

      it->_qtd += qtd;
    }
  }
}

void Venda::efetuaVenda(int cod, int qtd) {

  for (auto it = this->m_celulares.begin(); it != this->m_celulares.end();
       it++) {

    if (it->_codigo == cod) {

      if (it->_qtd >= qtd) {

        it->_qtd -= qtd;
      }
    }
  }
}

void Venda::aplicaDesconto(const std::string &fabricante, float desconto) {

  for (auto it = this->m_celulares.begin(); it != this->m_celulares.end();
       it++) {

    if (it->_fabricante == fabricante) {

      it->_valor -= (it->_valor * desconto) / 100;
    }
  }
}

void Venda::removeModelo(int cod) {

  for (auto it = this->m_celulares.begin(); it != this->m_celulares.end();
       it++) {

    if (it->_codigo == cod) {

      this->m_celulares.erase(it);
      break;
    }
  }
}

void Venda::imprimeEstoque() const {

  for (auto it = this->m_celulares.begin(); it != this->m_celulares.end();
       it++) {

    if (it->_qtd == 0) {
      continue;
    }

    cout << it->_fabricante << " " << it->_modelo << ", " << it->_armazenamento
         << "GB"
         << ", " << it->_memoria << "GB RAM"
         << ", ";

    cout << std::fixed << std::setprecision(0) << (it->_peso) * 1000
         << " gramas"
         << ", ";

    cout << toupper(it->_cor[0]) << it->_cor.substr(2) << ", " << it->_qtd;

    if (it->_qtd == 1) {
      cout << " restante";
    } else {
      cout << " restantes";
    }

    cout << ", "
         << "R$ " << std::fixed << std::setprecision(2) << it->_valor << endl;
  }
}
