#include<stdio.h>
#include<stdlib.h>

struct BstNode{
    int data;
    struct BstNode *left;
    struct BstNode *right;
};

int FindMin(struct BstNode* root)
{
    if(root == NULL)
        return 9999999;
    int res = root->data;
    int lres = FindMin(root->left);
    int rres = FindMin(root->right);
    if(lres < res)
        res = lres;
    if(rres < res)
        res = rres;
    return res;
}

int FindMax(struct BstNode* root)
{
    if(root == NULL)
        return 0;
    int res = root->data;
    int lres = FindMax(root->left);
    int rres = FindMax(root->right);
    if(lres > res)
        res = lres;
    if(rres > res)
        res = rres;
    return res;
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
    root = Insert(root, 20);
    printf("Minimum element is : %d",FindMin(root));
    printf("\n");
    printf("Maximum element is : %d",FindMax(root));
}