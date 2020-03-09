#include <iostream>
#include <vector>

using namespace std;

struct node {
    int data;
    node* next;
};

void push(int value, node** head, node** tail) {
    node* newe = new node;
    newe->data = value;
    newe->next = NULL;

    if (*head == NULL) {
        *tail = *head = newe;
    }
    else {
        (*tail)->next = newe;
        *tail = newe;
    }
}

void display_simple(node* head) {
    // printa ate o ultimo valor
    node* temp;
    for (temp = head; temp != NULL; temp = temp->next)
    {
        cout << temp->data << "->";
    }
    cout << endl;
}

int pop(node** head, node** tail) {
    node* newe = new node;
    int x;
    newe = *head;

    x = newe->data;
    *head = newe->next;
    free(newe);
    if (*head == NULL) {
        *tail = NULL;
    }
    return x;
}

int main() {
    cout << "Hello User\n";
    node* head, * tail;
    head = NULL;
    tail = NULL;

    int map[6][6];

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            map[i][j] = 0;
        }
    }
    map[0][1] = 1;
    map[1][2] = 1;
    map[2][4] = 1;
    map[3][2] = 1;
    map[3][4] = 1;
    map[4][0] = 1;
    map[5][1] = 1;

    /*push(111, &head, &tail);
    push(222, &head, &tail);
    push(333, &head, &tail);
    push(444, &head, &tail);
    pop(&head, &tail);  
    display_simple(head);*/
}
