#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *left;
  struct node *right;
};
struct node* root= NULL;


void Print(struct node *root, int k1, int k2)
{
    if(root==NULL)
    return;
    if(root->data>k1)
    Print(root->left,k1,k2);

    if(root->data>=k1 && root->data<=k2)
    printf("%d ",root->data);

    if(root->data<k2)
    Print(root->right,k1,k2);
}
struct node* newNode(int data) 
{ 
    struct node* node = (struct node*)malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
  
    return (node); 
} 
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


int main()
{


    int item,n,i,k1,k2;
    scanf("%d",&n);
   
    scanf("%d%d",&k1,&k2);

    for(i=0;i<n;i++)
    {
        scanf("%d",&item);
    root= insert(root,item);

}
Print(root, k1, k2);

  getchar();
  return 0;
}