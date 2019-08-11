#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};

void append(int, struct node*);
void addition_at_beginning(struct node*);

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
	printf("Linked List before addition of node at beginning :- \n");
	while(temp != NULL)
	{
		printf("The data is : %d and next address is : %p>\n",temp->data,temp->next);
		temp = temp->next;
	}
	int loc;
	printf("Enter the location you want to delete in linked list : ");
	scanf("%d",&loc);
	int flag=0;
	if(loc>n)
	{
		printf("Location is invalid\n");
		flag=1;
	}
	else
	if(loc == 1)
	{
		temp = head;
		head = temp->next;
		temp->next = NULL;
		free(temp);
	}
	else
	{
		struct node *p = head;
		struct node *q;
		int i=1;
		while(i<loc-1)
		{
			p = p->next;
			i++;
		}
		q = p->next;
		p->next = q->next;
		q->next = NULL;
		free(q);
	}
	if(flag==0)
	{
		temp = head;
		printf("Linked list after deletion of node :- \n");
		while(temp != NULL)
		{
			printf("The data is : %d and next address is : %p>\n",temp->data,temp->next);
			temp = temp->next;
		}
	}
}
