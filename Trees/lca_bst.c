#include <stdio.h>
#include <stdlib.h>

struct treenode{
    int data;
    struct treenode *left;
    struct treenode *right;
};

// int* find(struct treenode * A,int a,int b)
// {
//     if(A!=NULL)
//     {
//      if(A->data==a || A->data==b)return A;
//      struct treenode*x = find(A->left,a,b);
//      struct treenode*y = find(A->right,a,b);
//      if(x!=NULL && y!=NULL)return A;
//      if(x!=NULL)return x;
//      if(y!=NULL)return y;
//      return NULL;
//     }
//     return NULL;    
// }
// int ifpresent(struct treenode *A,int b)
// {
//     if(A!=NULL)
//     {
//         if(A->data==b)return 1;
//         int d=ifpresent(A->left,b);
//         int e=ifpresent(A->right,b);
//         return d||e;
//     }
//     return 0;
// }
// int lca(struct treenode* A, int B, int C) {
//     int c=ifpresent(A,B);
//     int d=ifpresent(A,C);
//     if(c==0 || d==0)return -1;
//     struct treenode* res=find(A,B,C);
//     return res->data;
// }

struct treenode* lca(struct treenode* root, int n1, int n2)
{
    while(root != NULL)
    {
        if(root->data > n1 && root->data > n2)
            root = root->left;
        else if(root->data < n1 && root->data < n2)
            root = root->right;
        else
            break;
    }
    return root;
}