// // #include <stdio.h> 
  
// // struct Node { 
// //     int data; 
// //     struct Node *left, *right; 
// // }; 

// // struct Node* newNode(int data); 
// // int search(int arr[], int strt, int end, int value); 
  
// // struct Node* buildUtil(int in[], int post[], int inStrt, int inEnd, int* pIndex) 
// // { 
// //     if (inStrt > inEnd) 
// //         return NULL; 
// //     struct Node* node = newNode(post[*pIndex]); 
// //     (*pIndex)--; 
// //     if (inStrt == inEnd) 
// //         return node; 
// //     int iIndex = search(in, inStrt, inEnd, node->data); 
// //     node->right = buildUtil(in, post, iIndex + 1, inEnd, pIndex); 
// //     node->left = buildUtil(in, post, inStrt, iIndex - 1, pIndex); 
// //     return node; 
// // } 
  
// // struct Node* buildTree(int in[], int post[], int n) 
// // { 
// //     int pIndex = n - 1; 
// //     return buildUtil(in, post, 0, n - 1, &pIndex); 
// // } 
  
// // int search(int arr[], int strt, int end, int value) 
// // { 
// //     int i; 
// //     for (i = strt; i <= end; i++) { 
// //         if (arr[i] == value) 
// //             return i;
// //     }
// // } 
  
// // struct Node* newNode(int data) 
// // { 
// //     struct Node* node = (struct Node*)malloc(sizeof(struct Node)); 
// //     node->data = data; 
// //     node->left = node->right = NULL; 
// //     return (node); 
// // } 
  
// // void preOrder(struct Node* node) 
// // { 
// //     if (node == NULL) 
// //         return; 
// //     printf("%d ", node->data); 
// //     preOrder(node->left); 
// //     preOrder(node->right); 
// // } 
  
// // int main() 
// // { 
// //     int in[] = { 4, 8, 2, 5, 1, 6, 3, 7 }; 
// //     int post[] = { 8, 4, 5, 2, 6, 7, 3, 1 }; 
// //     int n = sizeof(in) / sizeof(in[0]); 
// //     struct Node* root = buildTree(in, post, n); 
// //     preOrder(root);   
// //     return 0; 
// // }





// #include<stdio.h>
// #include<stdlib.h>

// typedef struct bst
// {
//     int val;
//     struct bst* left;
//     struct bst* right;
// }Tree;

// void preOrder(Tree* r)
// {

//     if( r== NULL)
//         return;
//     printf("%d ", r->val);
//     preOrder(r->left);
//     preOrder(r->right);
// }

// int search(int post[],int start,int end,int k)          // Searching given num in inorder array
// {
//     int i;
//     for(i=start;i<=end;i++)
//     {
//         if(post[i] == k)
//             return i;
//     }
// }

// Tree* createTree(int in[],int post[], int start,int end,int *index)     // creating Tree
// {
//     if(start > end)
//         return NULL;
    
//     int i = search(post,start,end,in[(*index)--]);
//     Tree *newnode = (Tree*)malloc(sizeof(Tree));
//     newnode->val = post[i];
//     newnode->right = createTree(in,post,i+1,end,index);     
//     newnode->left = createTree(in,post,start,i-1,index);
//     /* right is taken first because in post order is left->right->root
//      we start from end here so after root we have to find right of that node */ 
//     return newnode;     
// }

// int main()
// {
//     int n;
//     scanf("%d",&n);
//     int inorder[n];
//     int postorder[n];
//     for(int i=0;i<n;i++)
//     {
//         scanf("%d",&inorder[i]);        // scanning in-order  array
//     }
//     for(int i=0;i<n;i++)
//     {
//         scanf("%d",&postorder[i]);      // scanning post-order array
//     }
//     n--;
//     Tree *root = createTree(inorder,postorder,0,n,&n); 

//     /* here root will be the main binary tree   */
//     preOrder(root);
//     return 0;
// }


#include<stdio.h>
#include<stdlib.h>

typedef struct bst
{
    int val;
    struct bst* left;
    struct bst* right;
}Tree;
void preOrder(Tree* root)
{
    if(root == NULL)
    return;
    printf("%d ",root->val);
    preOrder(root->left);
    preOrder(root->right);
}
int search(int in[],int start,int end,int k)          // Searching given num in inorder array
{
    for(int i=start;i<=end;i++)
    {
        if(in[i] == k)
            return i;
    }
}
Tree* createTree(int in[],int post[], int start,int end,int *index)     // creating Tree
{
    if(start > end)
        return NULL;
    
    int i = search(in,start,end,post[(*index)--]);
    Tree *newnode = (Tree*)malloc(sizeof(Tree));
    newnode->val = in[i];
    newnode->right = createTree(in,post,i+1,end,index);     
    newnode->left = createTree(in,post,start,i-1,index);
    /* right is taken first because in post order is left->right->root
     we start from end here so after root we have to find right of that node */ 
    return newnode;     
}

int main()
{
    int n;
    scanf("%d",&n);
    int inorder[n];
    int postorder[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&inorder[i]);        // scanning in-order  array
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&postorder[i]);      // scanning post-order array
    }
    n--;
    Tree *root = createTree(inorder,postorder,0,n,&n); 

    /* here root will be the main binary tree   */
    preOrder(root);
    return 0;
}