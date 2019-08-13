#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};

struct node* RemoveDuplicates(struct node *head)
{
	struct node *ptr = head;
	while(ptr->next != NULL)
	{
		if(ptr && ptr->next)
		{
			if(ptr->data == ptr->next->data)
				ptr->next = ptr->next->next;
			else
				ptr = ptr->next;
		}
	}
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
	struct node *head = NULL;
	head = push(head, 1);
	head = push(head, 2);
	head = push(head, 2);
	head = push(head, 3);
	head = push(head, 3);
	Print(head);
	printf("\n");
	RemoveDuplicates(head);
	Print(head);
	printf("\n");
}

