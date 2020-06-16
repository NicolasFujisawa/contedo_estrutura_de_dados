#include <iostream>

using namespace std;

template<typename T>
struct node { /* pilha encadeada: Last in First out */
    T data;
    node* next;
};

template<typename T>
void push(T data, node<T>* head) {
    node<T>* last = new node<T>;
    last->next = NULL;
    last->data = data;

    if (!head->next) {
        head->next = last;
        return;
    }

    last->next = head->next;
    head->next = last;

    node<T>* temp = head;
    

    temp->next = last;
}

template<typename T>
T pop(node<T>* head) {
    T lixo;
    if (!head->next)
        return head->data;
    lixo = head->next->data;
    if (!head->next->next) { /* verifica se e o ultimo */
        free(head->next);
        head->next = NULL;
    }
    else { /* conecta o end next com o Node next.next */

        node<T>* temp = head->next;
        head->next = head->next->next;
        free(temp);
        temp = NULL;
    }
    return lixo;
}

template<typename T>
T top(node<T>* head) {
    return head->next->data;
}

template<typename T>
bool empty(node<T>* head) {
    if (!head->next) {
        return true;
    }
    return false;
}

template<typename T>
void display(node<T> *head) {
    node<T>* p;
    for (p = head->next; p != NULL; p = p->next) {
        cout << p->data << "->" << flush;
    }       
    cout << "NULL" << endl;
} 

string infixaParaPosfixa(string infix) { /*  (A+B*(C-D*(E-F)-G*H)-I*3)  */
    char x;
    string posfix;
    node<char>* pilha = new node<char>; /* pilha de caracteres */
    pilha->next = NULL;
    int n, i, j;
    n = infix.length();

    push(infix[0], pilha); /* empilha primeira ’(’ */
    for (j = 0, i = 1; i < n; i++) {
        switch (infix[i]) {
        case '(': 
            push(infix[i], pilha); /* empilha */
            break;
        case ')': 
            while (true) { /* desempilha */
                x = pop(pilha);
                if (x == '(') 
                    break;
                posfix += x; /* adiciona em posfix */
            }
            break;
        case '+': /* mesma função para '-' */
        case '-': 
            while (true) { /* desempilha até antes do '(' */
                x = top(pilha);
                if (x == '(') break;
                pop(pilha);
                posfix += x;
            }
            push(infix[i], pilha); /* empilha '-' ou '+' */
            break;
        case '*':
        case '/': 
            while (true) {
                x = top(pilha);
                if (x == '(' || x == '+' || x == '-')
                    break;
                pop(pilha);
                push(x, pilha);
            }
            push(infix[i], pilha);
            break;
        default: /* letras A | B | C*/
            posfix += infix[i];
        }
    }
    free(pilha);
    return posfix;
}


int main() {
    
    node<int>* stack = new node<int>;
    string infix;
    cin >> infix;
    cout << infixaParaPosfixa(infix) << endl;

    stack->next = NULL;
    
    if (!empty(stack)) {
        pop(stack);
    }
    push(1, stack);
    pop(stack);
    push(2, stack);
    push(3, stack);
    push(4, stack);
    pop(stack);
    pop(stack);

    // pop(stack);
    display(stack);

    
    return 0;
}