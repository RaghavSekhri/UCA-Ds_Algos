// // #include<stdio.h>
// // #include<stdlib.h>

// // struct TreeNode
// // {
// //     int val;
// //     struct TreeNode* left;
// //     struct TreeNode* right;
// // };

// // struct TreeNode* newNode(int data)
// // {
// //     struct TreeNode* temp = (struct TreeNode*) malloc (sizeof(struct TreeNode));
// //     temp->val = data;
// //     temp->left = temp->right = NULL;
// //     return temp;
// // }

// // int search(int *preorder, int start, int end, int val)          
// // {
// //     int i;
// //     for(i=start;i<=end;i++)
// //     {
// //         if(preorder[i] == val)
// //             break;
// //     }
// //     return i;
// // }
// // struct TreeNode* make(int *preorder, int *inorder, int start, int end, int preIndex)     
// // {
// //     if(start > end || preIndex < 0)
// //         return NULL;
    
// //     struct TreeNode* newnode = newNode(preorder[preIndex]);
// //     int inIndex = search(inorder, start, end, preorder[preIndex]);
// //     newnode->left = make(preorder, inorder, start, inIndex-1, preIndex+1);
// //     newnode->right = make(preorder, inorder, inIndex+1, end, preIndex + inIndex - start +1);
// // }

// // struct TreeNode* buildTree(int* preorder, int preorderSize , int inorder, int inorderSize)
// // {
// //     if(preorderSize = 0)
// //         return NULL;
// //     return make(preorder, inorder, 0 ,preorderSize-1, 0);
// // }








// #include<stdio.h>
// #include<stdlib.h>

// struct Tree{
//     int val;
//     struct bst* left;
//     struct bst* right;
// };

// int search(int in[],int start,int end,int k)          // Searching given num in inorder array
// {
//     for(int i=start;i<=end;i++)
//     {
//         if(in[i] == k)
//             return i;
//     }
// }

// struct Tree* createTree(int in[],int pre[], int start,int end,int *index)     // creating Tree
// {
//     if(start > end)
//         return NULL;
    
//     int i = search(in,start,end,pre[(*index)--]);      // finding node in inorder array
//     struct Tree* newnode = (struct Tree*)malloc(sizeof(struct Tree));
//     newnode->val = in[i];
//     newnode->left = createTree(in,pre,start,i-1,index);
//     newnode->right = createTree(in,pre,i+1,end,index);
//     return newnode;     
// }

// int main()
// {
//     int n;
//     scanf("%d",&n);
//     int inorder[n];
//     int preorder[n];
//     for(int i=0;i<n;i++)
//     {
//         scanf("%d",&inorder[i]);        // scanning in-order  array
//     }
//     for(int i=0;i<n;i++)
//     {
//         scanf("%d",&preorder[i]);      // scanning pre-order array
//     }
//     n--;
//     struct Tree *root = createTree(inorder,preorder,0,n,&n); 

//     return 0;
// }




#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
typedef struct TreeNode {
        int val;
        struct TreeNode *left;
        struct TreeNode *right;

  }TreeNode;


void postOrder(TreeNode* r)
{

    if( r== NULL)
        return;
    postOrder(r->left);
    postOrder(r->right);
    printf("%d ", r->val);
}

int SearchElement(int *pre,int start,int end,int k)
{
  int i;
  for(i=start;i<=end;i++)
  {
    if(pre[i] == k)
      return i;
  }
}

TreeNode* buildTree(int* in, int* pre,int start,int end,int *index) 
{
  if(start>end)
    return NULL;
  int i = SearchElement(pre,start,end,in[(*index)++]);
  TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
  temp->val = pre[i];
  temp->left = buildTree(in,pre,start,i-1,index);
  temp->right = buildTree(in,pre,i+1,end,index);
  return temp;
}

int main()
{

    int n, i;

    scanf("%d", &n);
    int in[n], pre[n];
    for(i=0;i<n;i++)
    {
        scanf("%d", &in[i]);
    }
    for(i=0;i<n;i++)
    {
        scanf("%d", &pre[i]);
    }
  int index = 0;
    TreeNode* Res = buildTree(in,pre,0,n-1,&index);

    postOrder(Res);
}