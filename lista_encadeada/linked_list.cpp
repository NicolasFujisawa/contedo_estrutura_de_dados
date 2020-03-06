#include "linked_list.h"
#include <iostream>

using namespace std;


/***********************************************/
/*
*   insere um node no ultimo local
*/
/***********************************************/
void LinkedList::push_back(node* head, int value) {
    node* nod = new node;
    nod->data = value;
    nod->next = NULL;
    
    while (head->next){
        head = head->next;
    }

    head->next = nod;
}


void LinkedList::display(node* head){
    node* temp = head->next;
    // printa ate o ultimo valor
    if (temp){
        cout << temp->data << "->";
        LinkedList::display(temp);
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
int LinkedList::at(node* head, int index, int count) {
    count++;
    node* temp = head->next;
    if (count <= index && temp) {
        return LinkedList::at(temp, index, count);
    }
    else {
        return temp->data;
    }
}

/***********************************************/
/*
*   insere valor antes do node com index passado
*/
/***********************************************/
void LinkedList::push_at(node* head, int value, int index) {
    node* new_node = new node;
    new_node->data = value;
    new_node->next = NULL;
    
    for (int i = 0; i < index; i++){
        if (!head->next)continue;
        head = head->next;
    }
    
    new_node->next = head->next;
    head->next = new_node;

}

void LinkedList::push(node* head, int value) {
    node* temp = new node;
    temp->data = value;
    temp->next = head->next;
    head->next = temp;
}

/***********************************************/
/*
*   delete o endereco do index
*/
/***********************************************/
void LinkedList::pop_back(node* head) { /* exclui da memoria o ultimo elemento da lista */
    if (!head->next) return; /* se n tiver sido inicialidaza, volta */

    while (head->next->next) { /* percorre ate o penultimo elemento */
        head = head->next;
    }

    free(head->next); /* libera a ultima memoria */
    head->next = NULL;
}

void LinkedList::pop(node* head) {
    if (!head->next) return;

    if (!head->next->next) { /* verifica se e o ultimo */
        free(head->next);
        head->next = NULL;
    }
    else { /* conecta o end next com o node next.next */
        node* temp = head->next;
        head->next = head->next->next;
        free(temp);
        temp = NULL;
    }
}

void LinkedList::pop_at(node* head, int index, int count) {
    if (!head->next) return;
    if (!index >= LinkedList::size(head)) index = LinkedList::size(head) - 1;
    cout << "idx: " << index << endl;


    node* temp = new node;
    temp = head->next;

    while (count < index) {
        head = temp;
        temp = temp->next;
        count++;
    }
    cout << "prev: " << head->data <<" temp: " << temp->data << endl;
    head->next = temp->next;
    
    free(temp);
    temp = NULL;

}

int LinkedList::size(node* head) {
    if (head->next == NULL) {
        return 0;
    }
    if (head->next->next == NULL) {
        return 1;
    }
    return LinkedList::size(head->next) + 1;
}

// sem cabeca

void LinkedList::display_simple(node* head) {
    // printa ate o ultimo valor
    node* temp;
    for (temp = head; temp != NULL; temp = temp->next)
    {
        cout << temp->data << "->";
    }
    cout << endl;
}

void LinkedList::push_back_simple(node* curr, int value) {
    node* temp = new node;
    temp->data = value;
    temp->next = NULL;

    if (!curr) {
        LinkedList::push_simple(&curr, value);
        cout << "1";
        return;
    }
    cout << "2";
    while (curr) {
        curr = curr->next;
    }
    
    curr->next = temp;

}

void LinkedList::push_simple(node** curr, int value) {
    node* temp = new node;
    temp->data = value;

    temp->next = *curr;
    *curr = temp;
}

void LinkedList::pop_simple(node** temp) {
    node* toPop;
    toPop = *temp;
    *temp = (*temp)->next;
    free(toPop);
}