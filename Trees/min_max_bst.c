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
    {
        printf("Tree is Empty");
        return -1;
    }
    else if(root->left == NULL)
        return root->data;
    return FindMin(root->left);
}

int FindMax(struct BstNode* root)
{
    if(root == NULL)
    {
        printf("Tree is Empty");
        return -1;
    }
    else if(root->right == NULL)
        return root->data;
    return FindMin(root->right);
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