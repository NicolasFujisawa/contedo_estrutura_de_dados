#include "uri_1110.h"
/* URI 1110
Dada uma pilha de n cartas enumeradas de 1 até n com a carta 1 no topo e a carta n na base.  A seguinte operação é ralizada enquanto
tiver 2 ou mais cartas na pilha.

Jogue fora a carta do topo e mova a próxima carta (a que ficou no topo) para a base da pilha.

Sua tarefa é encontrar a sequência de cartas descartadas e a última carta remanescente.

Cada linha de entrada (com exceção da última) contém um número n ≤ 50. A última linha contém 0 e não deve ser processada. Cada número
de entrada produz duas linhas de saída. A primeira linha apresenta a sequência de cartas descartadas e a segunda linha apresenta a
carta remanescente.

Entrada
A entrada consiste em um número indeterminado de linhas contendo cada uma um valor de 1 até 50. A última linha contém o valor 0.

Saída
Para cada caso de teste, imprima duas linhas. A primeira linha apresenta a sequência de cartas descartadas, cada uma delas separadas
por uma vírgula e um espaço. A segunda linha apresenta o número da carta que restou. Nenhuma linha tem espaços extras no início ou
no
final. Veja exemplo para conferir o formato esperado.
*/
//input 
/*
7
19
10
6
0
*/
//ouput
/*
Discarded cards: 1, 3, 5, 7, 4, 2
Remaining card: 6
Discarded cards: 1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 4, 8, 12, 16, 2, 10, 18, 14
Remaining card: 6
Discarded cards: 1, 3, 5, 7, 9, 2, 6, 10, 8
Remaining card: 4
Discarded cards: 1, 3, 5, 2, 6
Remaining card: 4
*/

#include <iostream>
#include<vector>

using namespace std;

int throwingCardsAway(int number, vector<int>* discarted) {
    vector<int> queue;
    vector<int>::iterator it;
    discarted->clear();
    for (int i = number; i > 0; i--) {
        queue.push_back(i);
    }

    while (queue.size() > 0) {

        if (queue.size() == 1) {
            return queue.at(0);
        }

        discarted->push_back(queue.back());
        queue.pop_back();

        it = queue.begin();
        queue.insert(it, queue.back());

        queue.pop_back();
    }

}

void display(int remaing, vector<int> discarted) {
    cout << "Discarted cards: ";
    for (int i = 0; i < discarted.size(); i++) {
        if (i == discarted.size() - 1) {
            cout << discarted.at(i) << endl;
        }
        else {
            cout << discarted.at(i) << ", ";
        }
    }
    cout << "Remaining card: " << remaing << endl;
}

int main() {
    cout << "Hello User!\nInsert a amount of cards:";

    int input, remaining;
    vector<int> discarted;
    do {
        cin >> input;
        if (input == 0) {
            continue;
        }
        remaining = throwingCardsAway(input, &discarted);
        display(remaining, discarted);

    } while (input != 0);

}
