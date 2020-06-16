#include <iostream>
#include <vector>
#include <string>

// liked list
#include "linked_list.h"
#include "param_model.h"

using namespace std;
int main()
{
    //menu
    int option = -1, value, index;

    //lista encadeada com cabeça
    node* head = new node;
    head->next = NULL; /* [  |]->NULL */
  
    //lista encadeada sem cabeca
    node* curr;
    curr = NULL; /* NULL */

    List::Option type = List::Option::SIMPLE;

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

        if (type == List::Option::HEAD) {
            switch (option) {
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
        else { /* lista encadeada sem cabeca */
            switch (option) {
            case 1:
                cin >> value;
                LinkedList::push_back_simple(curr, value);
                break;
            case 2:

                break;
            case 3:
                cout << "digite valor: ";
                cin >> value;
                LinkedList::push_simple(&curr, value);
                break;
            case 4:
                LinkedList::display_simple(curr);
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                LinkedList::pop_simple(&curr);
                break;
            case 8:
                break;
            case 9:
                break;

            default:
                break;
            }
        }
    }
}