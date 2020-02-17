#include "linked_list.h"
struct node
{
    int data;
    node* next;
};

void LinkedList::list() {
    head = nullptr;
    tail = nullptr;
}