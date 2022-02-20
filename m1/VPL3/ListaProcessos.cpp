#include "ListaProcessos.hpp"

void ListaProcessos::adicionar_processo(Processo* proc){
    if (this->head == nullptr){
        head = proc;
        tail = proc;
    } else {
        Processo* current = head; //row access

        while(current != nullptr){
            
            if(current->_prioridade < proc->_prioridade || current->_prioridade == proc->_prioridade){

                if (current == head){ //change the head

                if (current->_id < proc->_id && current->_prioridade == proc->_prioridade){ //respect the order
                    current = current->next;
                    continue;
                }

                if (head->next == nullptr){ //head erro
                    head = proc;
                    head->next = tail;
                    tail->previous = head;
                    continue;
                }
            
                proc->next = current->next;
                current->next->previous = proc;

                swap(proc,head);
                }

                else if (current != tail){ //add in the middle
    
                if (current->_id < proc->_id && current->_prioridade == proc->_prioridade){ //respect the order
                    current = current->next;
                    continue;
                }

                proc->next = current->next;
                proc->previous = current->previous;
                current->previous->next = proc;
                current->next->previous = proc;

                swap(proc,current);
                }

                else if (current == tail){ //change the tail

                if (current->_id < proc->_id && current->_prioridade == proc->_prioridade){ //respect the order
                    current = current->next;
                    continue;
                }

                proc->previous = tail->previous;
                tail->previous->next = proc;

                swap(proc,tail);
                }
            }
            current = current->next;
        }
        //normal add
        tail->next = proc;
        proc->previous = tail;
        tail = proc;
    }
}

Processo* ListaProcessos::remover_processo_maior_prioridade(){
    Processo* aux = nullptr;
    aux = this->head;
    this->head = this->head->next;
    this->head->previous = nullptr;
    aux->next = nullptr;

    return aux;
}

Processo* ListaProcessos::remover_processo_menor_prioridade(){
    Processo* aux = nullptr;
    aux = this->tail;
    this->tail = this->tail->previous;
    this->tail->next = nullptr;
    aux->previous = nullptr;

    return aux;
}

Processo* ListaProcessos::remover_processo_por_id(int id){
    Processo* current = this->head;
    while(current != nullptr){

        if(current->_id == id){ 
            if (current == this->head){ //head erro
                this->head = current->next;
                current->next->previous = nullptr;
                current->next = nullptr;
                return current;
            }
            current->next->previous = current->previous;
            current->previous->next = current->next;

            current->next = nullptr;
            current->previous = nullptr;

            return current;
        }
        current = current->next;
    }
    return nullptr;
}

void ListaProcessos::imprimir_lista(){
    Processo* current = this->head;
    while (current != nullptr){

        current->imprimir_dados();

        current = current->next;
    }
}
