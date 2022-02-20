#include <iostream>

#include "Handler.h"

void fer_assert(const bool expr, const char* msg) {
  if (!expr) {
    std::cout << msg << std::endl;
    exit(1);
  }
}

void HandlerAdd::handle(Instruction *inst) {

    if(inst->msg == "add"){

        if(this->_stack->size() < 2){
            fer_assert(0, "Erro: poucos argumentos na pilha.");
        }
        
        int v1 = this->_stack->top(); //reading and removing the two top values in the stack
        
        this->_stack->pop();
        
        int v2 = this->_stack->top();
        
        this->_stack->pop();
        
        int v = v1 + v2; //Adding v1 and v2 (call the result v), pushing v onto the stack
        
        this->_stack->push(v);

        return;
    }

    fer_assert(0, "Erro: comando desconhecido.");
}

void HandlerMul::handle(Instruction *inst) {

    if(inst->msg == "mul"){

        if(this->_stack->size() < 2){
            fer_assert(0, "Erro: poucos argumentos na pilha.");
        }

        int v1 = this->_stack->top(); //reading and removing the two top values in the stack
        this->_stack->pop();
        
        int v2 = this->_stack->top();
        this->_stack->pop();
        
        int v = v1 * v2; //Multiplying v1 and v2 (call the result v), pushing v onto the stack
        
        this->_stack->push(v);

        return;
        
    }

    this->_next->handle(inst);
}

void HandlerPop::handle(Instruction *inst) {

    if(inst->msg == "pop"){

        if(this->_stack->empty()){
            fer_assert(0, "Erro: poucos argumentos na pilha.");
        }

        this->_stack->pop();
        return;
    }

    this->_next->handle(inst);
}

void HandlerPrint::handle(Instruction *inst) {

    if(inst->msg == "print"){

        if(this->_stack->empty()){
            fer_assert(0, "Erro: poucos argumentos na pilha.");
        }
        
        std::cout << this->_stack->top() << std::endl;
        return;
    }

    this->_next->handle(inst);
}

void HandlerPush::handle(Instruction *inst) {

    if(inst->msg == "push"){

        this->_stack->push(inst->value);
        return;
    }

    this->_next->handle(inst);
}