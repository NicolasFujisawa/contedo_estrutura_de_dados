#include <iostream>
#include <algorithm>

using namespace std; 

 struct node {
    int value;
    node* left;
    node* right;
    node() : value(0), left(nullptr), right(nullptr) {}
    node(int x) : value(x), left(nullptr), right(nullptr) {}
    node(int x, node* left, node* right) : value(x), left(left), right(right) {}
};

 int answer;

int dfs(node* root) {
    if (root == NULL) {
        return 0;
    }
    int x = dfs(root->left);
    int y = dfs(root->right);

    int answer = max(answer, x + y + root->value);
    return root->value + max(x, y);
}

int maxpathSum(node* root) {
    answer = INT_MIN;
    dfs(root);
    return answer;
}

int main()
{
    
}
