#include <stdio.h>
#include<stdlib.h>

struct BstNode{
int data;
struct BstNode *left;
struct BstNode *right;
};

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

int Search(struct BstNode* root, int data)
{
    if(root == NULL)
        return 0;
    else if(root->data == data)
        return 1;
    int res1 = Search(root->left, data);
    int res2 = Search(root->right, data);
    return res1 || res2;
}

 int main()
 {
    struct BstNode *root = NULL;
    root = Insert(root, 15);
    root = Insert(root, 10);
    root = Insert(root, 20);
    int number; 
    printf("Enter number to be searched : ");
    scanf("%d",&number);
    if(Search(root, number) == 1)
        printf("Found");
    else
        printf("Not Found");
 }
