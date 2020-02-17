#include "linked_list.h"

void LinkedList::list() {
    head = nullptr;
    tail = nullptr;
}

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
*   
*   retorna o valor no indice passado
*
*/
/***********************************************/
int LinkedList::valueAtIndex(int index)
{
    node* temp = new node;
    temp = head;

    for (int i = 0; i < index; i++)
    {
        if (temp == nullptr) {
            continue;
        }
        temp = temp->next;
    }

    return temp->data;
}
