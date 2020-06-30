#include <iostream>
#include <algorithm>

using namespace std; 

struct node {
    //int value;
    int key;
    node* left;
    node* right;

    node() : key(0), left(NULL), right(NULL) {
        
    }
    node(int k) : key(k), left(NULL), right(NULL) {
    
    }
};


int altura(node* root) { /*  */
    if (root == NULL)
        return 0; /* a altura de uma árvore vazia é 0 */
    
    int left = altura(root->left);
    int right = altura(root->right);
    return max(left, right) + 1;
}

/* Pegar o diametro de uma arvore */
int diameterOfBinaryTree(node* root) {
    return altura(root);
}

static int minimo(node* root) {
    if (root == NULL) {
        return 0;
    }

    while (root->left) {
        root = root->left;
    }

    return root->key;
}

static node* dfs(node* root, int k) {
    if (root == NULL || root->key == k) {
        return root;
    }

    if (root->key > k) {
        return dfs(root->left, k);
    }
    return dfs(root->right, k);

    /*while (root != NULL || root->key != k) { versão iterativa
        if (root->key > k) {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }*/
}


//static node* removeKey(node* root, int k) {
//    node* target = dfs(root, k);
//    return remove(target);
//}

static node* remove(node* root) {
    if (root == NULL) {
        return root;
    }
    
    node* prev, * aux;

    if (root->left == NULL) {
        aux = root->right;
    }
    else {
        prev = root; 
        aux = root->left;
        while (aux->right != NULL) {
            prev = aux;
            aux = aux->right;
        }
        if (prev != root) {
            prev->right = aux->left;
            aux->left = root->left;
        }

        aux->right = root->right;
    }

    free(root);
    return aux;
}


/* algoritmo de varredura */
static void displayErd(node* root) {
    if (root != NULL) {
        displayErd(root->left);
        cout << root->key << ", ";
        displayErd(root->right);
    }
}

node* pushNode(node* root, node* leaf) {
    node* f, * p;

    if (!root) {
        return leaf;
    }

    f = root;
    p = f;
    while (f != NULL) {
        p = f;
        if (f->key > leaf->key) { /* se for maior -> esquerda*/
            f = f->left;
        }
        else {
            f = f->right;
        }
    }

    if (p->key > leaf->key) {
        p->left = leaf;
    }
    else {
        p->right = leaf;
    }

    return root;

}

int main()
{
    node* root = new node(5);     
    root = pushNode(root, new node(3));
    root = pushNode(root, new node(1));
    root = pushNode(root, new node(4));
    root = pushNode(root, new node(0));
    root = pushNode(root, new node(2));
    root = pushNode(root, new node(8));
    root = pushNode(root, new node(6));
    root = pushNode(root, new node(9));
    root = pushNode(root, new node(7));

    /*
    *        5
    *      /   \
    *    3       8
    *   / \     / \
    *  1   4   6   9
    * / \       \
    *0   2       7
    *
    */

    displayErd(root);

    cout << diameterOfBinaryTree(root) << endl;
    // root = removeKey(root, 7);
    root = remove(root);
    displayErd(root);

    //root = removeKey(root, 8);
    cout << diameterOfBinaryTree(root) << endl;
}
