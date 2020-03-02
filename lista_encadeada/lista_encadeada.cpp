#include <iostream>
#include <vector>
#include <string>

// liked list
#include "linked_list.h"

using namespace std;

/*1 - Faça uma função para concatenar duas listas encadeadas

2 - Faça uma função para remover elementos repetidos de uma lista encadeada (apenas uma varredura).

3 - Faça uma função que converta um vetor em lista encadeada (mantenha a ordem)

4 - Faça uma função para intercalar duas listas encadeadas*/

int main()
{
    //menu
    int option = -1, value, index;

    //lista encadeada com cabeça
    LinkedList* list = new LinkedList;

    node* head = new node;
    head->next = NULL;

    vector<int> array;
    while (option != 0)
    {
        cout << ".1 push back" << endl;
        cout << ".2 push_at" << endl;
        cout << ".3 push" << endl;
        cout << ".4 display" << endl;
        cout << ".5 at" << endl;
        cout << ".6 pop_back" << endl;
        cout << ".7 pop" << endl;
        cout << ".8 pop_at" << endl;
        cout << ".9 size" << endl;
        cout << ".0 Sair" << endl;

        cin >> option;

        switch (option)
        {
        case 1:
            cout << "digite valor: ";
            cin >> value;
            LinkedList::push_back(head, value);
            break;
        case 2:
            cout << "valor:";
            cin >> value;
            cout << "index:";
            cin >> index;
            LinkedList::push_at(head, value, index);
            break;
        case 3:
            cout << "digite valor: ";
            cin >> value;
            LinkedList::push(head, value);
            break;
        case 4:
            LinkedList::display(head);
            break;
        case 5:
            cout << "index: ";
            cin >> index;
            cout << "value: " << LinkedList::at(head, index) << endl;
            break;
        case 6:
            LinkedList::pop_back(head);
            LinkedList::display(head);
            break;
        case 7:
            LinkedList::pop(head);
            LinkedList::display(head);
            break;
        case 8:
            cin >> index;
            LinkedList::pop_at(head, index);
            LinkedList::display(head);
            break;
        case 9:
            cout << "size: " << LinkedList::size(head) << endl;
            break;
        default:
            break;
        }
    }
}