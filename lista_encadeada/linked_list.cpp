#include "linked_list.h"
#include <iostream>

using namespace std;

void LinkedList::list() {
    head = NULL;
    tail = NULL;
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
        tail = nod;
    }
    else {
        tail->next = nod;
        tail = nod;
    }
}

node* LinkedList::getHead()
{
    return head;
}

void LinkedList::display(node* head){
    node* temp = head;
    // printa ate o ultimo valor
    if (temp != NULL){
        cout << temp->data << " -> ";
        LinkedList::display(temp->next);
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
void LinkedList::pushAt(int value, int index) {
    node* new_node = new node;
    node* temp = new node;
    new_node->data = value;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        tail = new_node;
    }
    else {
        temp = head;
        for (int i = 0; i < index - 1; i++){
            temp = temp->next;
        }

        if (temp->next == NULL) {
            temp->next = new_node;
            tail = new_node;
        }
        else {
            new_node->next = temp->next;
            temp->next = new_node;
        }
    }
}

void LinkedList::push(int value) {
    node* temp = new node;
    temp->data = value;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
        tail = temp;
    }
    else {
        temp->next = head;
        head = temp;
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