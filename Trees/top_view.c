#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct Node *left;
    struct Node *right;
};

int l=0,r=0;

void Top(struct node* root, int *arr, int *arr2, int a, int pri)
{
    int x = a;
    if(root == NULL)
        return;
    if(x<l)
        l = x;
    if(x>r)
        r = x;
    if(arr[250 + x] == -9999999)
    {
        arr[250 + x] = root->data;
        arr2[250 + x] = pri;
    }
    else
    if(arr2[250 + x] > pri)
    {
        arr[250 + x] = root->data;
        arr2[250 + x] = pri;
    }
    Top(root->left, arr, arr2, x-1, pri+1);
    Top(root->right, arr, arr2, x+1, pri+1);
}

void topView(struct node *root)
{
    int *arr = (int*) malloc (sizeof(int)*500);
    for(int i=0;i<500;i++)
        arr[i] = -9999999;
    int *arr2 = (int*) malloc (sizeof(int)*500);
    int mid = 250;
    int a = 0;
    int pri = 0;
    Top(root, arr, arr2, a, pri);
    for(int i=250+l;i<=250+r;i++)
        printf("%d ",arr[i]);
}