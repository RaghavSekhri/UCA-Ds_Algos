#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* insert( struct Node* root, int data ) {
        
    if(root == NULL) {
    
        struct Node* node = (struct Node*)malloc(sizeof(struct Node));

        node->data = data;

        node->left = NULL;
        node->right = NULL;
        return node;
      
    } else {
      
        struct Node* cur;
        
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

int max(int a, int b)
{
    return (a>b) ? a : b;
}

int height(struct Node* node)
{
  if (node==NULL)
    return 0;
  else  
    return 1 + max(height(node->left), height(node->right));
}


int diameter(struct Node * tree)
{
  if (tree == NULL)
     return 0;
  int lheight = height(tree->left);
  int rheight = height(tree->right);
  int ldiameter = diameter(tree->left);
  int rdiameter = diameter(tree->right);
  return max(lheight + rheight + 1, max(ldiameter, rdiameter));
}

int main() {
  
    struct Node* root = NULL;
    int t;
    int data;
    scanf("%d", &t);
    while(t-- > 0) {
        scanf("%d", &data);
        root = insert(root, data);
    }
    int d =diameter(root);
    printf("%d",d);
    return 0;
}