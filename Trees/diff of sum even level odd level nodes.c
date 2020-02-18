#include <stdio.h>

int getLevelDiff(struct node *root) 
{
   if (root == NULL) 
         return 0; 
   return root->data - getLevelDiff(root->left) - getLevelDiff(root->right); 
} 