#include "usuario.hpp"

Usuario::Usuario(const std::string& login, const std::string& password) {
  this->_login = login;
  this->_password = password;
}

string Usuario::getLogin() const {
  
  return this->_login;
}

string Usuario::getPassword() const {

  return this->_password;
}

void Usuario::setPassword(const string& password) {
  this->_password = password;
}

void Usuario::setLogin(const string& login) {
  this->_login = login;
}