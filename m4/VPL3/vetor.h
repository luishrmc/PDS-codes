#pragma once

#include <cassert>
#include <vector>

// Define um vetor de qualquer Tipo cujos índices variam em
// qualquer intervalo, inclusive negativos.
template <class Tipo> 
class Vetor {
  public:
    // Cria um vetor cujos índices variam de 'inicio' até 'fim'.
    // PRECONDIÇÃO: fim >= inicio.
    Vetor(int inicio, int fim);

    // Altera o valor do índice i.
    // PRECONDIÇÃO: i está dentro do intervalo de índices do vetor.
    void atribuir(int i, Tipo valor);

    // Retorna o valor do índice i.
    // PRECONDIÇÕES: 
    // (1) i está dentro do intervalo de índices do vetor.
    // (2) i foi inicializando anteriormente.
    Tipo valor(int i) const; 
  
  private:
    int inicio_;  // Primeiro índice válido do vetor.
    int fim_;  // Último índice válido do vetor.
    std::vector<Tipo> elementos_;  // Elementos do vetor.
    std::vector<int> ind_; //Indices que foram inicializados
};

// DEFINIÇÃO DAS CLASSES DE EXCEÇÃO.

// Lançada quando o intervalo [inicio, fim] não contém nenhum índice.
struct ExcecaoIntervaloVazio {
  int inicio;  // Índice de início do arranjo que lançou a excecao.
  int fim;  // Índice de fim do arranjo que lançou a excecao.
};

//Lançada quando 'indice' não pertence a [inicio, fim].
struct ExcecaoIndiceInvalido {
  int inicio;  // Índice de início do arranjo que lançou a excecao.
  int fim;  // Índice de fim do arranjo que lançou a excecao.
  int indice;  // Índice inválido. 
};

// Lançada quando o valor de 'indice' é solicitado e o mesmo não foi previamente
// inicializado.
struct ExcecaoIndiceNaoInicializado {
  int indice;  // Índice do arranjo que não foi inicializado. 
};


// IMPLEMENTAÇÃO DOS MÉTODOS DA CLASSE.

template <class Tipo> 
Vetor<Tipo>::Vetor(int inicio, int fim) : 
    inicio_(inicio), 
    fim_(fim) {
  
  if(!(this->fim_ >= this->inicio_)){ //erro
    ExcecaoIntervaloVazio e;
    e.inicio = inicio; e.fim = fim;
    throw ExcecaoIntervaloVazio(e);
  }

  elementos_.resize(fim - inicio + 1);
}

template <class Tipo> 
void Vetor<Tipo>::atribuir(int i, Tipo valor) {

  if(this->inicio_ > i || this->fim_ < i){
    ExcecaoIndiceInvalido e;
    e.inicio = this->inicio_; e.fim = this->fim_; e.indice = i;
    throw ExcecaoIndiceInvalido(e);
  }

  this->ind_.push_back(i);


  int j = i - inicio_;
  elementos_[j] = valor;
}

template <class Tipo> 
Tipo Vetor<Tipo>::valor(int i) const {

  if(this->inicio_ > i || this->fim_ < i){
    ExcecaoIndiceInvalido e;
    e.inicio = this->inicio_; e.fim = this->fim_; e.indice = i;
    throw ExcecaoIndiceInvalido(e);
  }

  for(const int& elem : this->ind_){
    if(elem == i){
      int j = i - this->inicio_;
      return this->elementos_[j];
    }
  }

  ExcecaoIndiceNaoInicializado e;
  e.indice = i;
  throw ExcecaoIndiceNaoInicializado(e);

}