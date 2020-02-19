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

    node* tmp = new node;
    tmp->data = value;
    tmp->next = NULL;

    if (head == NULL)
    {
        head = tmp;
        tail = tmp;
    }
    else
    {
        tail->next = tmp;
        tail = tail->next;
    }
}

node* LinkedList::getHead()
{
    return head;
}

void LinkedList::display(node* head){

    // printa ate o ultimo valor
    if (head != NULL){
        cout << head->data << ", ";
        LinkedList::display(head->next);
    }
    else {
        cout << endl;
    }
}

/***********************************************/
/*
*   concatena duas linked list
*/
/***********************************************/
void LinkedList::concatList(node *head1, node *head2){

    if (head1 != NULL && head2 != NULL)
    {
        // procura a calda da lista
        if (head1->next == NULL) {
            head1->next = head2;
        }
        else {
            LinkedList::concatList(head1->next, head2);
        }
    }
}

/***********************************************/
/*
*   retorna valor do index
*/
/***********************************************/
int LinkedList::valueAtIndex(node* head1, int index, int count) {
    count++;
    if (head1 != NULL) {
        if (count <= index) {
            if (head1->next != NULL){
                return LinkedList::valueAtIndex(head1->next, index, count);
            }
            else {
                return head1->data;
            }
        }
        else {
            return head1->data;
        }
    }
}

/***********************************************/
/*
*   retorna node do index
*/
/***********************************************/
node* LinkedList::nodeAtIndex(node* head1, int index, int count) {
    count++;
    if (head1 != NULL) {
        if (count <= index) {
            if (head1->next != NULL) {
                return LinkedList::nodeAtIndex(head1->next, index, count);
            }
            else {
                return head1;
            }
        }
        else {
            return head1;
        }
    }
}