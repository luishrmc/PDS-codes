#include "google_password.hpp"
#include <cctype>
#include <iostream>

void GooglePassword::insert(const string &url, const string &login,
                            const string &password) {

  if (this->checkPassword(password) == true) {

    this->m_passwords.insert(
        std::pair<string, Usuario>(url, Usuario(login, password)));
  }
}

void GooglePassword::remove(const std::string &url) {

  for (auto it = this->m_passwords.begin(); it != this->m_passwords.end();
       it++) {

    if (it->first == url) {

      this->m_passwords.erase(it);
      break;
    }
  }
}

void GooglePassword::update(const std::string &url, const std::string &login,
                            const std::string &old_password,
                            const std::string &new_password) {

  for (auto it = this->m_passwords.begin(); it != this->m_passwords.end();
       it++) {

    if (it->first == url) {

      if (it->second.getPassword() == old_password &&
          this->checkPassword(new_password) == true) {

        it->second.setLogin(login);
        it->second.setPassword(new_password);
      }
    }
  }
}

void GooglePassword::printPasswords() {

  std::cout << this->m_passwords.size() << std::endl;

  for (auto it = this->m_passwords.begin(); it != this->m_passwords.end();
       it++) {

    std::cout << it->first << ": " << it->second.getLogin() << " and "
              << it->second.getPassword() << std::endl;
  }
}

bool GooglePassword::checkPassword(const std::string &password) const {

  bool result = false;

  if (6 < password.size() && password.size() < 50) {

    for (int i = 0; i < password.size(); i++) {

      if (password[i] == ' ') {

        return result;
      }

      else if (password[i] == '1') {
        if (password.substr(i, 6) == "123456") {
          return result;
        }
      }
    }

    result = true;
    return result;
  }

  else {
    return result;
  }
}
