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
	struct node *temp1,*p;
	int i=1;
	int loc;
	printf("Enter location at which you want to enter a node : ");
	scanf("%d",&loc);
	int flag=0;
	if(loc>n)
	{
		printf("Invalid location \n");
		flag=1;
	}
	else
	{
		p = head;
		while(i<loc)
		{
			p=p->next;
			i++;
		}
		temp1=(struct node*)malloc(sizeof(struct node));
		printf("Enter node data : ");
		scanf("%d",&temp1->data);
		temp1->next=NULL;
		temp1->next = p->next;
		p->next = temp1;
	}
	if(flag==0)
	{
		temp = head;
		printf("Linked list after addition of node at particular loction :- \n");
		while(temp != NULL)
		{
			printf("The data is : %d and next address is : %p>\n",temp->data,temp->next);
			temp = temp->next;
		}
	}
}
