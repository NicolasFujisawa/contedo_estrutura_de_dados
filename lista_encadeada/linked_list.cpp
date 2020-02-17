#include "linked_list.h"
#include <iostream>

using namespace std;

void LinkedList::list() {
    head = nullptr;
    tail = nullptr;
}

/***********************************************/
/*
*   inicia um node se n estiver sido iniciado
*/
/***********************************************/
void LinkedList::createNode(int value){
    node* temp = new node;
    temp->data = value;
    temp->next = nullptr;

    /* distinguindo manualmente */
    if (head == nullptr) {
        head = temp;
        tail = temp;
        temp = nullptr;
    }else{
        tail->next = temp;
        tail = temp;
    }
}

/***********************************************/
/*
*   retorna o valor no indice passado
*/
/***********************************************/
int LinkedList::valueAtIndex(int index)
{
    node* temp = new node;
    temp = head;

    // ate o ultimo index
    for (int i = 0; i < index; i++)
    {
        if (temp->next == nullptr) {
            continue;
        }
        temp = temp->next;
    }

    return temp->data;
}

node* LinkedList::getHead()
{
    return head;
}

void LinkedList::display(){
    node* temp = new node;
    temp = head;

    // printa ate o ultimo valor
    cout << "{";
    while (temp != nullptr)
    {
        cout << temp->data << ", ";
        temp = temp->next;
    }
    cout << "}" << endl;
}

/***********************************************/
/*
*   concatena duas linked list
*/
/***********************************************/
void LinkedList::concatList(struct node *node1){
    node* temp = new node;

    tail->next = node1;
    temp = tail;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    tail = temp;
}
