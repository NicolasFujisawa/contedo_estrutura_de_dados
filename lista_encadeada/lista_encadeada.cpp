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
    int option = -1, valor, index;
    //int input, output;

    //lista encadeada
    LinkedList* list1 = new LinkedList{};
    LinkedList* list2 = new LinkedList{};

    while (option != 0)
    {
        cout << "=-=-=-Menu-=-=-=" << endl;
        cout << ".1 push back valor" << endl;
        cout << ".2 display" << endl;
        cout << ".3 valor do index tal" << endl;
        cout << ".4 insira valor no index tal" << endl;
        cout << ".0 Sair" << endl;

        cin >> option;

        switch (option)
        {
        case 1:
            cout << "digite valor: ";
            cin >> valor;
            list1->push_back_node(valor);
            break;
        case 2:
            LinkedList::display(list1->getHead());
            break;
        case 3:
            cout << "index: ";
            cin >> index;
            cout << LinkedList::valueAtIndex(list1->getHead(), index) << endl;
            break;
        case 4:
            cout << "valor:";
            cin >> valor;
            cout << "index:";
            cin >> index;
            LinkedList::insertAt(list1->getHead(), valor, index);
        default:
            break;
        }
    }
}