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
    int option = -1;
    //int input, output;

    //lista encadeada
    LinkedList* list1 = new LinkedList{};
    LinkedList* list2 = new LinkedList{};

    while (option != 0)
    {
        cout << "=-=-=-Menu-=-=-=" << endl;
        cout << ".1 Faca uma funçao para concatenar duas listas encadeadas" << endl;
        cout << ".2 Faca uma funcao para remover elementos repetidos de uma lista encadeada (apenas uma varredura)." << endl;
        cout << ".3 Faca uma funcao que converta um vetor em lista encadeada (mantenha a ordem)" << endl;
        cout << ".4 Faca uma funcao para intercalar duas listas encadeadas" << endl;
        cout << ".0 Sair" << endl;

        cin >> option;

        switch (option)
        {
        case 1:
            list1->createNode(1);
            list1->createNode(2);
            list2->createNode(3);
            list2->createNode(4);
            cout << list1->valueAtIndex(8) << endl;
            list1->concatList(list2->getHead());
            cout << list1->valueAtIndex(8) << endl;
            list1->display();
            break;
        case 2:
            
            break;
        case 3:
            

            break;
        default:
            break;
        }
    }
}