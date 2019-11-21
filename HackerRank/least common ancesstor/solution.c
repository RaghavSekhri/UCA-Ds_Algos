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
            cur = insert(root->left, data);
            root->left = cur;
        } else {
            cur = insert(root->right, data);
            root->right = cur;
        }
    
        return root;
    }
}

int lca(struct node *root, int n1, int n2)
{
    if(root->data == n1 || root->data == n2)
        return -1;
    while(root != NULL)
    {
        if(root->data > n1 && root->data > n2)
            root = root->left;
        else if(root->data < n1 && root->data < n2)
            root = root->right;
        else
            break;
    }
    return root->data;
}

int main() {
  
    struct node* root = NULL;
    
    int t;
    int data;

    scanf("%d", &t);
    int z;
        for(int i=0;i<t;i++)
        {
            scanf("%d",&z);
            root = insert(root,z);
        }
        scanf("%d", &data);
        while(data--)
        {
            int x,y;
            scanf("%d %d", &x, &y);
            int u = lca(root, x, y);
            printf("%d", u);
            printf("\n");
        }
    return 0;
}
