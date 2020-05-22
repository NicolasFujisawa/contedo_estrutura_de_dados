#include <iostream>
#include <vector>
using namespace std;

namespace edd {
    template<class T>
    class Queue { /* First in Last out */
    private:
        T* container;
        int front; //s
        int back; 
        size_t size;
    public:
        /* define size */
        Queue(size_t size) : front(0), back(0), size(size) {
            container = new T[size];
        }

        void push(T data) {
            cout << "push: " << data << endl;
            if (back >= size) {
                back = 0;
            }
            container[back++] = data;
        }

        T pop() {
            cout << "pop: " << container[front] << endl;
            if (front >= size) {
                front = 0;
            }
            return container[front++];
        }

        bool operator==(bool boolean) const {
            //cout << front << " " << back << endl;
            if (front == back) {
                return !boolean;
            }
            return boolean;
        }

    };
}
using namespace edd;

int* distancias(int n, int A[6][6], int o) {
    int* d, x, y;
    Queue<int> queue(n);
    d = new int[n];
    for (x = 0; x < n; x++) {
        d[x] = -1;
    }
    d[o] = 0;
    //processo iterativo
    queue.push(o);
    while (queue == true) {
        x = queue.pop(); /* x sai da fila */
        for (y = 0; y < n; y++) {
            if (A[x][y] == 1 && d[y] == -1) {
                d[y] = d[x] + 1;
                queue.push(y); /* y entra na fila */
            }
        }
    }
    return d;
}

int main() {
    
    Queue<int> queue(10);

    queue.push(10);
    queue.push(20);
    if (queue == true) {
        cout << "nao esta vazia" << endl;
    }
    queue.pop(); // 10
    queue.pop(); // 20

    /* distancias entre cidades */
    int cidade[6][6]{ 0 };
    cidade[4][0]++;
    cidade[5][1]++;
    cidade[0][1]++;
    cidade[1][2]++;
    cidade[2][4]++;
    cidade[3][2]++;
    cidade[3][4]++;
    for (int x = 0; x < 6; x++) {
        for (int y = 0; y < 6; y++) {
            cout << cidade[x][y] << " " << flush;
        }
        cout << endl;
    }
    int* dist = distancias(6, cidade, 3);
    for (int i = 0; i < 6;i++) {
        cout << dist[i] << " " << flush;
    }
    
    return 0;
}