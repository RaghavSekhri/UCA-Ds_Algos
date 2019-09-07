int getNthFromLast(Node *head, int n)
{
    Node *temp = head;
    int count=0;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    int value = count-n;
    int count1=0;
    while(head != NULL)
    {
        if(count1 == value)
            return head->data;
        count1++;
        head = head->next;
    }
    return -1;
}
