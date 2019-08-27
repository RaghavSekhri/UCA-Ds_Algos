#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
struct node
{
    int val;
    struct node * next;
};
void append(struct node **h,int n)
{
  struct node * app_node=(struct node*)malloc(sizeof(struct node));
 
   app_node->val=n;
   
 app_node->next=NULL;
   struct node * current = (*h);
 
   if(*h==NULL)
  {
   *h=app_node;

    }
 
   else
 {
 while(current->next!=NULL)
   {
        current=current->next;
  }
    current->next=app_node;
 }

}
void push(struct node ** h,int n)

{
 
   struct node * new_node=(struct node*)malloc(sizeof(struct node));
  
  new_node->val=n;
  
  new_node->next=(* h);
 
   (*h)=new_node;

}
int main() {
    struct node * head1=NULL;
    int num=0;
    for(int i=0;i<3;i++)
    {
        scanf("%d",&num);
        append(&head1,num);
    }
    struct node * head2=NULL;
    for(int i=0;i<3;i++)
    {
        scanf("%d",&num);
        append(&head2,num);
    }
    struct node * res=NULL;
    while(head1!=NULL && head2!=NULL)
    {
        
        if(head1->val>=head2->val)
        {
            push(&res,head2->val);
            head2=head2->next;
        }
        else
        {
            push(&res,head1->val);
            head1=head1->next;
        }
        
    }
    if(head1!=NULL)
    {
        while(head1)
        {
            push(&res,head1->val);
            head1=head1->next;
        }
    }
    else if(head2!=NULL)
    {
        while(head2)
        {
            push(&res,head2->val);
            head2=head2->next;
        }
    }
    while(res)
    {
        printf("%d ",res->val);
        res=res->next;
    }
    return 0;
}



