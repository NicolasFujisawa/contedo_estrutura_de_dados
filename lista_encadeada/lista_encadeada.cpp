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

    //lista encadeada com cabeça
    LinkedList* list1 = new LinkedList;
    LinkedList* list2 = new LinkedList{};
       

    while (option != 0)
    {
        cout << ".1 push back valor" << endl;
        cout << ".2 display" << endl;
        cout << ".3 valor do index tal" << endl;
        cout << ".4 insira valor no index tal" << endl;
        cout << ".5 delete pelo index" << endl;
        cout << ".0 Sair" << endl;

        cin >> option;

        switch (option)
        {
        case 1:
            cout << "digite valor: ";
            cin >> valor;
            list1->push_back(valor);
            break;
        case 2:
            LinkedList::display(list1->getHead());
            break;
        case 3:
            cout << "index: ";
            cin >> index;
            cout << LinkedList::at(list1->getHead(), index) << endl;
            break;
        case 4:
            cout << "valor:";
            cin >> valor;
            cout << "index:";
            cin >> index;
            LinkedList::insertAt(list1->getHead(), valor, index);
            break;
        case 5:
            cout << "value:";
            cin >> valor;
            LinkedList::push(list1->getHead(), valor);
            break;
        case 6:
            //list1->pop();
            LinkedList::display(list1->getHead());
        default:
            break;
        }
    }
}