#include "fila.h"
#include "iostream"

struct No {
  int chave;
  No* proximo = nullptr;
};

Fila::Fila() {}

void Fila::Inserir(int k) {

  size++; //increasing the size

  if(this->primeiro_ == nullptr){

    No* process = new No;

    process->chave = k;
    this->primeiro_ = process;
    this->ultimo_ = process;
    return;
  }


  No* process = new No;

  process->chave = k; //key

  process->proximo = ultimo_; //aponta para o ultimo

  this->ultimo_ = process; //marca-se como novo ultimo
}

void Fila::RemoverPrimeiro() {
  try{

    if(this->primeiro_ == nullptr) throw ExcecaoFilaVazia();

  }catch(ExcecaoFilaVazia()){
    std::cerr << "EmptyException" << std::endl;
  }

  size--; //reducing the size

  if(this->primeiro_ == this->ultimo_){

    this->primeiro_ = nullptr;
    this->ultimo_ = nullptr;
    return;
  }

  No row; row.proximo = this->ultimo_;

  while(row.proximo->proximo != this->primeiro_){

    row.proximo = row.proximo->proximo;
  }

  this->primeiro_ = row.proximo;
  row.proximo->proximo = nullptr;
}

int Fila::primeiro() const {

  try{

    if(this->primeiro_ == nullptr) throw ExcecaoFilaVazia();

  }catch(ExcecaoFilaVazia()){
    std::cerr << "EmptyException" << std::endl;
  }

  return this->primeiro_->chave;
}

int Fila::ultimo() const {
  try{

    if(this->primeiro_ == nullptr) throw ExcecaoFilaVazia();

  }catch(ExcecaoFilaVazia()){
    std::cerr << "EmptyException" << std::endl;
  }

  return this->ultimo_->chave;
}

int Fila::tamanho() const {
  return this->size;
}