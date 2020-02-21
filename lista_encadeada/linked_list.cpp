#include "linked_list.h"
#include <iostream>

using namespace std;

void LinkedList::list() {
    head = NULL;
}

/***********************************************/
/*
*   insere um node no ultimo local
*/
/***********************************************/
void LinkedList::push_back(int value) {
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
*   retorna valor do index
*/
/***********************************************/
int LinkedList::at(node* head1, int index, int count) {
    count++;
    if (count <= index && head1->next != NULL) {
        return LinkedList::at(head1->next, index, count);
    }
    else {
        return head1->data;
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
    if (index == 0) {
        LinkedList::push(head, value);
    }
}

void LinkedList::push(node * node1, int value) {
    node* nod = new node;
    nod->data = value;
    nod->next = NULL;

    if (node1 == NULL) {
        node1 = nod;
    }
    else {
        nod->next = node1->next;
        node1->next = nod;
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

void LinkedList::pop() {
    node* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    delete temp;
    temp = NULL;
}