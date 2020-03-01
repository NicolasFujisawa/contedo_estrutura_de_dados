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
    if (count <= index && head->next != NULL) {
        return LinkedList::at(head->next, index, count);
    }
    else {
        return head->data;
    }
}

/***********************************************/
/*
*   retorna node do index
*/
/***********************************************/
node* LinkedList::nodeAtIndex(node* head, int index, int count) {
    count++;
    if (head != NULL && count <= index && head->next != NULL) {
        return LinkedList::nodeAtIndex(head->next, index, count);
    }
    else {
        return head;
    }
}

/***********************************************/
/*
*   insere valor antes do node com index passado
*/
/***********************************************/
void LinkedList::pushAt(node* head, int value, int index) {
    node* new_node = new node;
    new_node->data = value;
    
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
//void LinkedList::deleteAt(int index) {
//    try
//    {
//        node* del = head;
//
//        for (int i = 0; i < index; i++)
//        {
//            if (del->next != NULL) {
//                del = del->next;
//            }
//            else {
//                return;
//            }
//        }
//        if (del->next != NULL) {
//            if(del->next->next != NULL){
//                del->data = del->next->data;
//                del->next = del->next->next;
//            }
//            else {
//                del->data = del->next->data;
//                del->next = NULL;
//            }
//        }else{
//            delete del;
//            del = NULL;
//        }
//
//    }
//    catch (const std::exception& e)
//    {
//        cout << e.what();
//    }
//}

//void LinkedList::pop_back() {
//    node* temp = new node;
//    node* prev = new node;
//
//    if (temp->next == NULL) {
//        head = NULL;
//        delete temp;
//        delete prev;
//    }
//    else {
//        while (temp->next != NULL) {
//            prev = temp;
//            temp = temp->next;
//        }
//
//        prev->next = NULL;
//        delete temp;
//    }
//}
//
//void LinkedList::clear(){
//    node* next;
//
//    {
//        next = current->next;
//        free(current);
//        current = next;
//    }
//
//    head = NULL;
//}

int LinkedList::size(node* head) {
    if (head == NULL) {
        return 0;
    }
    if (head->next == NULL) {
        return 1;
    }
    return LinkedList::size(head->next) + 1;
}
