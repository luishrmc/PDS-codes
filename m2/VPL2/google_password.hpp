#ifndef GOOGLE_PASSWORD_H
#define GOOGLE_PASSWORD_H

#include "usuario.hpp"

#include <map>

/**
 * @brief Classe responsavel pelo armazenamento e gerenciamento das credenciais
 * salvas de um site.
 */
class GooglePassword {
 public:
  /**
   * @brief Adiciona uma nova credencial.
   * @param url Endereco do site.
   * @param login Login utilizado no cadastro.
   * @param password Password utilizado no cadastro.
   */
  void insert(const string& url,
              const string& login,
              const string& password);
    
    /**
   * @brief Atualiza as credenciais utilizadas em um site.
   * @param url Endereco do site.
   * @param login Novo login que deve ser atualizado.
   * @param old_password Password antigo.
   * @param new_password Novo password que deve ser atualizado.
   */

  void remove(const string& url);

  /**
   * @brief Remove as informacoes de um determinado site.
   * @param url Endereco do site.
   */

  void update(const string& url,
              const string& login,
              const string& old_password,
              const string& new_password);

  /**
   * @brief Verifica se o password passa em todas as restricoes
   *
   * @param password Password que sera verificado
   * @return true Verdadeiro se passa em todas as condicoes
   * @return false Falso se nao passa em pelo menos uma das condicoes
   */

  void printPasswords();

  /**
   * @brief Imprime as informacoes salvas de todos os sites.
   */

 private:

  bool checkPassword(const string& password) const;

  /**
   * @brief Verifica se o password passa em todas as restricoes
   *
   * @param password Password que sera verificado
   * @return true Verdadeiro se passa em todas as condicoes
   * @return false Falso se nao passa em pelo menos uma das condicoes
   */

  


 private:
  /**
   * @brief Container que armazena as informacoes salvas dos sites. Ele
   * utiliza a url do site como chave e as informacoes sao do tipo Usuario.
   * Logo, um site nao pode estar associado a mais de um usuario e senha.
   */
  std::map<string, Usuario> m_passwords;
};
#endif