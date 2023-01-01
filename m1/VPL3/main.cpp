#include "ListaProcessos.hpp"
#include "Processo.hpp"
#include <iostream>

void avaliacao_basica() {

  ListaProcessos lista;

  lista.adicionar_processo(new Processo(1, "Proc1", 3));
  lista.adicionar_processo(new Processo(2, "Proc2", 2));
  lista.adicionar_processo(new Processo(3, "Proc3", 1));
  lista.adicionar_processo(new Processo(4, "Proc4", 2));
  lista.adicionar_processo(new Processo(5, "Proc5", 5));

  lista.imprimir_lista();
  cout << "----------" << endl;

  Processo *maior_prioridade = lista.remover_processo_maior_prioridade();
  maior_prioridade->imprimir_dados();
  cout << "----------" << endl;

  lista.imprimir_lista();
  cout << "----------" << endl;

  Processo *menor_prioridade = lista.remover_processo_menor_prioridade();
  menor_prioridade->imprimir_dados();
  cout << "----------" << endl;

  lista.imprimir_lista();
  cout << "----------" << endl;

  Processo *processo_id = lista.remover_processo_por_id(1);
  processo_id->imprimir_dados();
  cout << "----------" << endl;

  processo_id = lista.remover_processo_por_id(1);
  if (processo_id == nullptr) {
    cout << "CORRECT" << endl;
  } else {
    cout << "ERROR";
  }
  cout << "----------" << endl;

  lista.imprimir_lista();
}

int main() {

  ListaProcessos lista;
  int id, prioridade;
  string nome;

  char data;
  while (cin >> data) {
    switch (data) {

    case 'a': {
      cin >> id, nome, prioridade;
      lista.adicionar_processo(new Processo(id, nome, prioridade));
      break;
    }

    case 'm': {
      lista.remover_processo_maior_prioridade();
      break;
    }

    case 'n': {
      lista.remover_processo_menor_prioridade();
      break;
    }
    case 'r': {
      cin >> id;
      lista.remover_processo_por_id(id);
      break;
    }

    case 'p': {
      lista.imprimir_lista();
      break;
    }
      // workspaceFolder

    case 'b': {
      avaliacao_basica();
      break;
    }
    }
  }
  return 0;
}
