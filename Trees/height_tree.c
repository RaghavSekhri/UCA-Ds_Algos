#include<stdio.h>
#include<stdlib.h>

struct BstNode{
    int data;
    struct BstNode *left;
    struct BstNode *right;
};

int Max(int lh, int rh)
{
    return (lh>rh) ? lh : rh;
}

int Height(struct BstNode *root)
{
    if(root == NULL)
        return -1;
    int lh = Height(root->left);
    int rh = Height(root->right);
    return Max(lh, rh) + 1;
}

struct BstNode* GetNewNode(int data)
{
    struct BstNode* newNode = (struct BstNode*) malloc (sizeof(struct BstNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct BstNode* Insert(struct BstNode *root, int data)
{
    if(root == NULL)
        root = GetNewNode(data);
    else if(data <= root->data)
        root->left = Insert(root->left, data);
    else if(data > root->data)
        root->right = Insert(root->right, data);
    return root;
}

int main()
{
    struct BstNode *root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 5);
    root = Insert(root, 7);
    root = Insert(root, 20);
    printf("Height of tree is : %d",Height(root));
}