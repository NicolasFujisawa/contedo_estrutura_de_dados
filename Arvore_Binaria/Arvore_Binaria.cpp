#include <iostream>
#include <algorithm>

using namespace std; 
static int minimo(node* root);
struct node {
    int value;
    node* left;
    node* right;
    node() : value(0), left(nullptr), right(nullptr) {}
    node(int x) : value(x), left(nullptr), right(nullptr) {}
    node(int x, node* left, node* right) : value(x), left(left), right(right) {}
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

static void pushNode(node* root, int value, bool left = true) {
    if (root == NULL) {
        return;
    }
    node* temp = new node(value);
    if (left) {
        root->left = temp;
    }
    else {
        root->right = temp;
    }
}

static node* remove(node* root, int value) {
    if (root == NULL) {
        return root;
    }

    if (value < root->value) { /* procura o valor */
        root->left = remove(root->left, value);
    }
    else if (root > root->right) {
        root->right = remove(root->right, value);
    }
    else { /* faz a remoção */
        if (root->left == NULL) {
            return root->right;
        }
        else if (root->right == NULL) {
            return root->left;
        }
        else {
            int substitute = minimo(root->right);
            root->value = substitute;
            root->right = remove(root->right, value);
        }

    }

    return root;
}

static int minimo(node* root) {
    if (root == NULL) {
        return 0;
    }

    while (root->left) {
        root = root->left;
    }

    return root->value;

}

int main()
{
    node* root = new node(5);               
    pushNode(root, 3);
    pushNode(root, 4, false);
    pushNode(root->left, 2);
    pushNode(root->left, 4, false);
    pushNode(root->right, 2);
    pushNode(root->right->left, 1);
    /*
    *        4
    *      /   \
    *    3       8
    *   / \     /
    *  2   4   7
    *         /
    *        6
    *
    */

    cout << diameterOfBinaryTree(root) << endl;
    remove(root, 1);
    cout << diameterOfBinaryTree(root) << endl;
}
