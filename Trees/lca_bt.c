#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* lca(struct Node *root, struct Node *n1, struct Node*n2)
{
    if(root == NULL)
        return NULL;
    if(root == n1 || root == n2)
        return root;
    struct Node* l = lca(root->left, n1, n2);
    struct Node* r = lca(root->right, n1, n2);
    if(l != NULL && r != NULL)
        return root;
    if(l == NULL && r == NULL)
        return NULL;
    return (l != NULL) ? l : r;
}