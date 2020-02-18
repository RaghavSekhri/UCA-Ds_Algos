#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

int FindMin(struct Node* root)
{
    if(root->left == NULL)
        return root->data;
    return FindMin(root->left);
}

struct Node* Delete(struct Node* root, int data)
{
    if(root == NULL)
        return root;
    else if(data < root->data)
        root->left = Delete(root->left, data);
    else if(data > root->data)
        root->right = Delete(root->right, data);
    else
    {
        // case:1 -> No Child
        if((root->left == NULL) && (root->right == NULL))
        {
            free(root);
            root = NULL;
        }
        // case:2 -> One Child
        else if(root->left == NULL)
        {
            struct Node* temp = root;
            root = root->right;
            free(temp);
        }
        else if(root->right == NULL)
        {
            struct Node* temp = root;
            root = root->left;
            free(temp);
        }
        // case:3 -> Two Child
        else
        {
            struct Node* temp = FindMin(root->right);
            root->data = temp->data;
            root->right = Delete(root->right, temp->data);
        }
    }
    return root;
}
