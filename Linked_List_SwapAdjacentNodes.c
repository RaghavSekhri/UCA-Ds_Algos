#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};

void swap(int *, int *);

void PairWiseSwap(struct node *head)
{
	struct node *temp = head;
	while(temp != NULL && temp->next != NULL)
	{
		swap(&temp->data,&temp->next->data);
		temp = temp->next->next;
	}
}

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

struct node* push(struct node *head,int data)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	if(head == NULL)
        	head = temp;
	else
	{
		struct node *temp1 = head;
		while(temp1->next != NULL)
			temp1 = temp1->next;
		temp1->next = temp;
	}
	return head;
}

void Print(struct node *head)
{
	while(head != NULL)
	{
		printf("%d ",head->data);
		head = head->next;
	}
}

int main()
{
	struct node *head =NULL;
	head = push(head, 5);
        head = push(head, 4);
	head = push(head, 3);
	head = push(head, 2);
	//head = push(head, 1);
	Print(head);
	printf("\n");
	PairWiseSwap(head);
	Print(head);
	printf("\n");
}

