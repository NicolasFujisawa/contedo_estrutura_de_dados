#include "linked_list.h"
#include <iostream>

using namespace std;

void LinkedList::list() {
    head = nullptr;
    tail = nullptr;
}

/***********************************************/
/*
*   insere um node no ultimo local
*/
/***********************************************/
void LinkedList::push_back_node(int value) {
    node* nod = new node;
    nod->data = value;
    nod->next = NULL;

    if (head == NULL) {
        head = nod;
    }
    else {
        node* temp = head;

        // percorre ate o temp chegar na ultima posicao
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nod;
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

/***********************************************/
/*
*   insere valor antes do node com index passado
*/
/***********************************************/
void LinkedList::insertAt(node* head, int value, int index) {
    node* nod = new node;
    nod->data = value;

    for (int i = 0; i < index; i++) {

        if (i + 1 == index) {
            nod->next = head->next;
            head->next = nod;
        }

        head = head->next;

        if (head->next == NULL) {
            break;
        }
    }

    if (index == 0) {
        nod->next = head;
    }
}

/***********************************************/
/*
*   delete o endereco do index
*/
/***********************************************/
void LinkedList::deleteAt(int index) {
    try
    {
        node* del = head;

        for (int i = 0; i < index; i++)
        {
            if (del->next != NULL) {
                del = del->next;
            }
            else {
                return;
            }
        }
        if (del->next != NULL) {
            if(del->next->next != NULL){
                del->data = del->next->data;
                del->next = del->next->next;
            }
            else {
                del->data = del->next->data;
                del->next = NULL;
            }
        }else{
            delete del;
            del = NULL;
        }

    }
    catch (const std::exception& e)
    {
        cout << e.what();
    }
}