bool areIdentical(struct Node *head1, struct Node *head2)
{
    int count=0,count1=0;
    Node *temp = head1;
    Node *temp1 = head2;
    while(temp->next != NULL)
    {
        count++;
        temp = temp->next;
    }
    while(temp1->next != NULL)
    {
        count1++;
        temp1 = temp1->next;
    }
    if(count != count1)
        return 0;
    else
    {
        while(head1 != NULL)
        {
            if(head1->data != head2->data)
                return 0;
            head1 = head1->next;
            head2 = head2->next;
        }
        return 1;
    }
}