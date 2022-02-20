#include <iostream>

#include "RingArray.h"

void fer_assert(const bool expr, const char* msg) {
  if (!expr) {
    std::cout << msg << std::endl;
    exit(1);
  }
}

template <class T, unsigned N>
void RingArray<T, N>::add(T value) {

    if( !(this->isFull()) ){

        if(this->_first == 8 && this->_last == 8){
            this->_first = 0;
            this->_last = 0;
        }

        this->buf[this->_last] = value;
        this->_last++;

    }else{
        fer_assert(0, "Erro: anel cheio.");
    }
}

template <class T, unsigned N>
T RingArray<T, N>::get() {
    
    if( !(this->isEmpty()) ){

        if(this->_first == 8 && this->_last == 8){
            this->_first = 0;
            this->_last = 0;
        }
        
        this->_first++;
        return this->buf[this->_first - 1];
    }
    else{
        
        fer_assert(0, "Erro: anel vazio.");
    }
}

template <class T, unsigned N>
bool RingArray<T, N>::isFull() const {

    if( (*(&this->buf + 1) - this->buf) -1 == int(this->_last) - int(this->_first) ){
    
    return true;  
    }
    else{

        return false;
    }
}

template <class T, unsigned N>
bool RingArray<T, N>::isEmpty() const {

  if(this->_last == this->_first){

    return true;
  }else{

    return false;
  }
}

template <class T>
void test_add_then_get() {
  RingArray<T, 8> r;
  T value;
  while (std::cin >> value) {
    r.add(value);
  }
  while (!r.isEmpty()) {
    std::cout << r.get() << std::endl;
  }
}

template <class T>
void test_add_or_get() {
  RingArray<T, 8> r;
  T value;
  char c;
  while (std::cin >> c) {
    if (c == '+') {
      std::cin >> value;
      r.add(value);
    } else if (c == '-') {
      std::cout << r.get() << std::endl;
    } else {
      std::cout << "Invalid operation\n";
    }
  }
}

int main () {
  char data;
  while (std::cin >> data) {
    switch (data) {
      case 'd': test_add_then_get<double>();
                break;
      case 's': test_add_then_get<std::string>();
                break;
      case 'D': test_add_or_get<double>();
                break;
      case 'S': test_add_or_get<std::string>();
                break;
      default: std::cout << "Invalid type\n";
    }
  }
  return 0;
}