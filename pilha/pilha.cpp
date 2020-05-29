#include <iostream>

using namespace std;

template<typename T>
struct node { /* pilha encadeada: Last in First out */
    T data;
    node* next;
};

template<typename T>
void push(T data, node<T>** list) {
    node<T>* last = new node<T>;
    last->next = NULL;
    last->data = data;

    if (!*list) {
        *list = last;
        return;
    }

    while ((*list)->next) {
        *list = (*list)->next;
    }

    (*list)->next = last;
    
}

template<typename T>
T pop(node<T>* list) {
    
}

template<typename T>
void display(node<T> *list) {
    node<T>* p;
    for (p = list; p != NULL; p = p->next) {
        cout << p->data << "->" << flush;
    }       
    cout << "NULL" << endl;
} 

int main() {
    
    node<int>* stack = new node<int>;
    stack = NULL;
    
    //pop(stack);
    push(1, &stack);
    push(2, &stack);
    push(2, &stack);

    push(2, &stack);

   // pop(stack);
    display(stack);

    
    return 0;
}