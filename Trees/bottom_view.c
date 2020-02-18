#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

struct node {
    
    int data;
    struct node *left;
    struct node *right;
  
};

struct node* insert( struct node* root, int data ) {
        
    if(root == NULL) {
    
        struct node* node = (struct node*)malloc(sizeof(struct node));

        node->data = data;

        node->left = NULL;
        node->right = NULL;
        return node;
      
    } else {
      
        struct node* cur;
        
        if(data <= root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
    
        return root;
    }
}

int l=0,r=0;

void Bottom(struct node *root, int *arr, int *arr2, int a, int pri)
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
    if(arr2[250 + x] < pri)
    {
        arr[250 + x] = root->data;
        arr2[250 + x] = pri;
    }
    
    Bottom(root->right, arr, arr2, x+1, pri+1);
    Bottom(root->left, arr, arr2, x-1, pri+1);
}

void bottomView(struct node *root)
{
    int *arr = (int*) malloc (sizeof(int)*500);
    for(int i=0;i<500;i++)
        arr[i] = -9999999;
    int *arr2 = (int*) malloc (sizeof(int)*500);
    int mid = 250;
    int a = 0;
    int pri = 0;
    Bottom(root, arr, arr2, a, pri);
    for(int i=250+l;i<=250+r;i++)
        printf("%d ",arr[i]);
}

int main() {
  
    struct node* root = NULL;
    
    int t;
    int data;

    scanf("%d", &t);

    while(t-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }
  
    bottomView(root);
    return 0;
}