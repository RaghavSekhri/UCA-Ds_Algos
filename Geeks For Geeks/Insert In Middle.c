Node* insertInMiddle(Node* head, int x)
{
    Node *temp1 = head;
    Node *temp2 = head;
    Node *temp = (Node*) malloc (sizeof(Node));
    temp->data = x;
    int count=0;
	while(temp1->next != NULL)
	{
	    count++;
	    temp1 = temp1->next;
	}
	int mid = count/2;
	int count1=0;
	while(temp2 != NULL)
	{
	    if(count1 == mid)
	    {
            temp->next = temp2->next;
            temp2->next = temp;
	    }
	    count1++;
	    temp2 = temp2->next;
	}
	return head;
}