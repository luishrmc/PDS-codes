// Copyright 2018 Universidade Federal de Minas Gerais (UFMG)

#include "complexo.h"

#include <cmath>

Complexo::Complexo() : Complexo(0, 0) {
}

Complexo::Complexo(double a) : Complexo(a, 0) {
}

Complexo::Complexo(double a, double b) {
    this->real_ = a;
    this->imag_ = b;
}

double Complexo::real() const {
  return this->real_;
}

double Complexo::imag() const {
  return this->imag_;
}

bool Complexo::operator==(Complexo x) const {
  if(this->real_ == x.real_ && this->imag_ == x.imag_){
      return true;
  }
  return false;
}

void Complexo::operator=(Complexo x) {
  this->real_ = x.real_;
  this->imag_ = x.imag_;
} 

double Complexo::modulo() const {
  return sqrt( pow(this->real_,2) + pow(this->imag_,2) );
}

Complexo Complexo::conjugado() const {
  Complexo c;
  c.real_ = this->real_;
  c.imag_ = (this->imag_)*-1;
  return c;
}

Complexo Complexo::operator-() const {
  Complexo c;
  c.real_ = (this->real_)*-1;
  c.imag_ = (this->imag_)*-1;
  return c;
}

Complexo Complexo::inverso() const {
  Complexo i;
  i.real_ = this->real_/( pow(this->real_,2) + pow(this->imag_,2) );
  i.imag_ = (this->imag_)*-1/( pow(this->real_,2) + pow(this->imag_,2) );
  return i;
}

Complexo Complexo::operator+(Complexo y) const {
  Complexo s(this->real() + y.real(), this->imag() + y.imag());
  return s;
}

Complexo Complexo::operator-(Complexo y) const {
  return (*this) + -y;
}

Complexo Complexo::operator*(Complexo y) const {
  Complexo p;
  p.real_ = this->real_*y.real_ - this->imag_*y.imag_;
  p.imag_ = this->real_*y.imag_ + this->imag_*y.real_;
  return p;
}

Complexo Complexo::operator/(Complexo y) const {
  Complexo i;
  i.real_ = (this->real_*y.real_ + this->imag_*y.imag_)/( pow(y.real_,2) + pow(y.imag_,2) );
  i.imag_ = (y.real_*this->imag_ - this->real_*y.imag_)/( pow(y.real_,2) + pow(y.imag_,2) );
  return i;
}
