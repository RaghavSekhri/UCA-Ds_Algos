#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};

void append(int, struct node*);
void length(struct node*);

int main()
{
	int n;
	struct node *head = NULL;
	printf("How many elements you want to enter in a linked list : ");
	scanf("%d",&n);
        append(n,head);
	return 0;
}

void append(int n,struct node* head)
{
	struct node *temp;
	for(int i=0;i<n;i++)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		printf("Enter %d node data : ",i+1);
		scanf("%d",&(temp->data));
		temp->next = NULL;
		if(head == NULL)
			head = temp;
		else
		{
			struct node *p;
			p = head;
			while(p->next != NULL)
				p=p->next;
			p->next = temp;
		}
	}
	temp = head;
	length(temp);
}
void length(struct node* temp)
{
	int count=0;
	while(temp!=NULL)
	{
		count++;
		temp=temp->next;
	}
	-printf("The length of the linked list is : %d \n",count);
}
