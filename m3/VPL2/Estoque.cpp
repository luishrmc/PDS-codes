#include <string>
#include <iostream>

#include "Estoque.hpp"

void Estoque::add_mercadoria(const std::string& mercadoria, unsigned int qtd) {
    
    for(auto it = this->tabela.begin(); it != tabela.end(); it++){
      if(it->first == mercadoria){
          it->second += qtd;
          return;
        }
    }

    this->tabela.insert(std::pair<std::string, int> (mercadoria, qtd));
}

void Estoque::sub_mercadoria(const std::string& mercadoria, unsigned int qtd) {

    for(auto it = this->tabela.begin(); it != tabela.end(); it++){
        if(it->first == mercadoria){
            if(it->second < qtd){
                std::cout << mercadoria << " insuficiente" << std::endl;
                return;
            }
            else{
                it->second -= qtd;
                return;
            }
        }
    }
    std::cout << mercadoria << " inexistente" << std::endl;
}

unsigned int Estoque::get_qtd(const std::string& mercadoria) const {
    
    for(auto it = this->tabela.begin(); it != this->tabela.end(); it++){
        if(it->first == mercadoria){
            return it->second;
        }
    }

    return 0;
}

void Estoque::imprime_estoque() const {

    for(auto it = this->tabela.begin(); it != this->tabela.end(); it++){
        std::cout << it->first << ", " << it->second << std::endl;
    }
}

Estoque& Estoque::operator += (const Estoque& rhs) {

    if(this->tabela.size() == 0){
        for(auto tabR = rhs.tabela.begin(); tabR != rhs.tabela.end(); tabR++){
            this->add_mercadoria(tabR->first,tabR->second);
        }
        return *this;
    }

    if(rhs.tabela.size() == 0){
        return *this;
    }

    for(auto tabR = rhs.tabela.begin(); tabR != rhs.tabela.end(); tabR++){
        bool isadd = false;

        for(auto tabL = this->tabela.begin(); tabL != this->tabela.end(); tabL++){

            if(tabR->first == tabL->first){
                tabL->second += tabR->second;
                isadd = true;
                break;
            }
        }

        if(isadd == false){
            this->add_mercadoria(tabR->first,tabR->second);
        }
    }

  return *this;
}

Estoque& Estoque::operator -= (const Estoque& rhs) {
    
    for(auto tab = this->tabela.begin(); tab != this->tabela.end(); tab++){
        
        for(auto tabR = rhs.tabela.begin(); tabR != rhs.tabela.end(); tabR++){
            
            if(tabR->first == tab->first){
                tab->second -= tabR->second;
            }
            
        }
    }

    return *this;
}

bool operator < (Estoque& lhs, Estoque& rhs) {

    for(auto tabL = lhs.tabela.begin(); tabL != lhs.tabela.end(); tabL++){

        bool iscomp = false;

        for(auto tabR = rhs.tabela.begin(); tabR != rhs.tabela.end(); tabR++){
            
            if(lhs.tabela.size() == rhs.tabela.size() && lhs.tabela.size() == 1){
                if(tabL->second == tabR->second && tabL->first == tabR->first)
                return false;
            }

            if(tabL->first == tabR->first){
                iscomp = true;
                if(tabL->second >= tabR->second){
                    return false;
                }
                break;
            }
        }

        
        if(iscomp == false){
            return false;
        }
    }
    return true;
}

bool operator > (Estoque& lhs, Estoque& rhs) {

    return (rhs < lhs);
}
