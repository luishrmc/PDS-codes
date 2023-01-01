#include <list>
#include <math.h>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

#include "LineProcessor.hpp"

void LinePrinter::processaLinha(const std::string &str) {
  std::cout << str << std::endl;
}

bool ContadorPopRural::linhaValida(const std::string &str) const {
  // Neste exemplo usaremos expressoes regulares para verificar se uma linha
  // eh valida ou nao.
  //
  // Esta expressao regular eh formada por cinco partes. Cada uma dessas
  // partes eh um dos tres tipos de padrao regular abaixo:
  //
  // \\w+ eh qualquer palavra com um ou mais digitos, letras e sublinhas (_)
  // \\s* eh qualquer sequencia de zero ou mais espacos (inclui tab)
  // \\d+ eh qualquer sequencia de um ou mais digitos
  std::regex regularExpr("\\w+\\s*\\d+\\s*\\d+");

  // A funcao regex_match vai retornar verdadeiro se a string str casa-se com
  // a expressao regular que acabamos de criar:
  return std::regex_match(str, regularExpr);
}

void ContadorPopRural::processaLinha(const std::string &str) {
  //
  // Em geral eh mais facil ler dados de uma string se a string eh transformada
  // em um objeto do tipo stringstream:
  std::stringstream ss(str);
  //
  // Iremos ler os dados da string nestas tres variaveis abaixo:
  std::string nomePais;
  unsigned populacao, percUrbana;
  //
  // Como sabemos que a linha contem string int int, podemos fazer a leitura
  // facilmente usando o operador de streaming:
  ss >> nomePais >> populacao >> percUrbana;
  //
  // Note que precisamos arredondar o valor que serah impresso. O arredondamento
  // serah feito via a funcao floor. Ou seja, decimais serao sempre
  // arredondados para baixo:
  unsigned popRural = floor(populacao - (populacao * (percUrbana / 100.0)));
  //
  // Uma vez encontrados os valores que precisam ser impressos, seguimos o
  // modelo do enunciado do exercicio:
  std::cout << popRural << " pessoas vivem no campo no " << nomePais
            << std::endl;
}

bool ContadorNumNaturais::linhaValida(const std::string &str) const {

  for (int i = 0; i < str.size(); i++) {
    if (str[i] != 32) {
      if (!(isdigit(str[i]))) {
        return false;
      }
    }
  }

  return true;
}

void ContadorNumNaturais::processaLinha(const std::string &str) {

  int sum = 0;
  std::string num;

  std::stringstream ss(str);
  while (ss >> num) {
    sum += stoi(num);
  }
  std::cout << sum << std::endl;
}

bool LeitorDeFutebol::linhaValida(const std::string &str) const {
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '_')
      return false;
  }
  std::regex regularExpr("\\s*\\w+\\s*\\d+\\s*\\w+\\s*\\d+");
  return std::regex_match(str, regularExpr);
}

void LeitorDeFutebol::processaLinha(const std::string &str) {
  std::stringstream ss(str);
  int g1, g2;
  std::string t1, t2;
  ss >> t1 >> g1 >> t2 >> g2;

  if (g1 > g2)
    std::cout << "Vencedor: " << t1 << std::endl;
  else if (g1 < g2)
    std::cout << "Vencedor: " << t2 << std::endl;
  else
    std::cout << "Empate" << std::endl;
}

void ContadorDePalavras::processaLinha(const std::string &str) {
  int numWords = 0;
  std::stringstream ss(str);
  std::string aux;

  while (ss >> aux) {
    numWords++;
  }

  if (numWords != 0)
    std::cout << numWords << std::endl;
}

bool InversorDeFrases::linhaValida(const std::string &str) const {
  for (int i = 0; i < str.size(); i++) {
    if (str[i] != 32) {
      if (!(isalpha(str[i]))) {

        return false;
      }
    }
  }
  return true;
}

void InversorDeFrases::processaLinha(const std::string &str) {
  std::list<std::string> invert;
  std::stringstream ss(str);
  std::string word;

  while (ss >> word) {
    invert.push_front(word);
  }

  for (auto &x : invert) {
    std::cout << x << ' ';
  }
  std::cout << std::endl;
}

bool EscritorDeDatas::linhaValida(const std::string &str) const {
  std::regex dateFormat("\\s*\\d\\d?/\\d\\d?/\\d{4}");

  return std::regex_match(str, dateFormat);
}

void EscritorDeDatas::processaLinha(const std::string &str) {
  std::istringstream ss(str);
  std::string data;
  std::string result;

  ss >> data;

  for (int i = 0; i < data.size(); i++) {
    if (data[i] == '/') {
      result += data[i + 1];
      result += data[i + 2];
      break;
    }
  }

  std::vector<std::string> month = {"0",   "Jan", "Fev", "Mar", "Abr",
                                    "Mai", "Jun", "Jul", "Ago", "Set",
                                    "Out", "Nov", "Dez"};
  std::cout << month[stoi(result)] << std::endl;
}
