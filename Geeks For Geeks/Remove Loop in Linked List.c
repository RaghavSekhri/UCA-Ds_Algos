void removeLoop(Node *loop_node, Node* head)
{
    Node *ptr1 = loop_node, *ptr2 = loop_node;
    int count = 1;
    while(ptr1->next != ptr2)
    {
        ptr1 = ptr1->next;
        count++;
    }
    ptr1 = head;
    ptr2 = head;
    for(int i=0;i<count;i++)
        ptr2 = ptr2->next;
    while(ptr2 != ptr1)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    ptr2 = ptr2->next;
    while(ptr2->next != ptr1)
        ptr2 = ptr2->next;
    ptr2->next = NULL;
}
void removeTheLoop(Node *head)
{
    Node *slow_p = head,*fast_p = head;
    while(slow_p != NULL && fast_p != NULL && fast_p->next != NULL)
    {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if(slow_p == fast_p)
            removeLoop(slow_p,head);
    }
}