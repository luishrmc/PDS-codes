#include <iostream>
#include "QuadroAlocacao.hpp"
#include "Disciplina.hpp"

using std::cin;
using std::cout;
using std::endl;

void avaliacao_basica() {
    
    QuadroAlocacao quadro_alocacao;

    quadro_alocacao.inserir_alocacao("XYZ", "DISC2", "Seg-Qua", "14:55-16:35", "2003");
    quadro_alocacao.inserir_alocacao("XYZ", "DISC2", "Seg-Qua", "19:00-20:40", "2003");

    quadro_alocacao.inserir_alocacao("ABC", "DISC1", "Ter-Qui", "14:55-16:35", "3015");
    quadro_alocacao.inserir_alocacao("ABC", "DISC1", "Ter-Qui", "07:30-09:10", "3015");

    quadro_alocacao.imprimir_alocacao_completa();
    cout << "----------" << endl;

    quadro_alocacao.remover_alocacao_disciplina("ABC", "07:30-09:10");

    quadro_alocacao.imprimir_alocacao_completa();
    cout << "----------" << endl;

    vector<Disciplina> mais_ofertadas = quadro_alocacao.recuperar_disciplinas_mais_ofertadas();
    for (Disciplina &disciplina : mais_ofertadas)
        disciplina.imprimir_alocacao();    
    
}

int main(){
    QuadroAlocacao quadro_alocacao;
    char data;
    string codigo, nome, dia, horario, sala;

    while(cin >> data){
        switch (data){
            case 'a':{
                cin >> codigo; cin >> nome; cin >> dia; cin >> horario; cin >> sala;
                quadro_alocacao.inserir_alocacao(codigo,nome,dia,horario,sala);
                break;
            }
            case 'm':{
                vector<Disciplina> result;
                result = quadro_alocacao.recuperar_disciplinas_mais_ofertadas();
                for(auto it = result.begin(); it != result.end(); it++){
                    it->imprimir_alocacao();
                }
                break;
            }
            case 'r':{
                cin >> codigo; cin >> horario;
                quadro_alocacao.remover_alocacao_disciplina(codigo,horario);
                break;
            }
            case 'p':{
                quadro_alocacao.imprimir_alocacao_completa();
                break;
            }
            case 'b':{
                avaliacao_basica();
                break;
            }
        
        }
    }

    return 0;
}
