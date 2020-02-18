#include <iostream>
#include <queue> 

using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

void LevelOrder(struct Node *root)
{
    if(root == NULL)
        return;
    queue <struct Node*> Q;
    Q.push(root);
    while(!Q.empty())
    {
        struct Node *curr = Q.front();
        cout<<curr->data<<" ";
        if(curr->left != NULL)
            Q.push(curr->left);
        if(curr->right != NULL)
            Q.push(curr->right);      
        Q.pop();  
    }
}