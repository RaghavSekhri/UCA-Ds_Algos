int countNodes(Node *n)
{
    int count = 1;
    Node *temp = n;
    while(temp->next != n)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
int countNodesinLoop(struct Node *head)
{
    Node *slow_p = head,*fast_p = head;
    while(slow_p != NULL && fast_p != NULL && fast_p->next != NULL)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if(slow_p == fast_p)
            return countNodes(slow_p);
    }
    return 0;
}