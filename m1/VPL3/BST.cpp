#include "BST.hpp"

NodeT* creatNode(int data){
    NodeT* aux = new NodeT;
    aux->data = data;
    aux->esq = nullptr;
    aux->dir = nullptr;
    return aux;
}

void BST::insertNode(int data){
    if (root != nullptr){
        insertNodeHelper(root, data);
    } else {
        root = creatNode(data);
    }
}

void BST::insertNodeHelper(NodeT* n, int data){
    if (data < n->data){
        if (n->esq == nullptr){
            n->esq = creatNode(data);
        } else {
            insertNodeHelper(n->esq,data);
        }
    } else if (data > n->data){
        if (n->dir == nullptr){
            n->dir = creatNode(data);
        } else {
            insertNodeHelper(n->dir, data);
        }
    }
}

void inorder (NodeT* n ){
    if (n == nullptr)
    return;

    inorder(n->esq);
    cout << n-> data << ' ';
    inorder(n->dir);
}

void BST::display(){
    inorder(root);
    cout << endl;
}