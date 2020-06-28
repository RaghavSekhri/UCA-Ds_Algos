int getNthFromLast(Node *head, int n)
{
//     Node *temp = head;
//     int count=0;
//     while(temp != NULL)
//     {
//         count++;
//         temp = temp->next;
//     }
//     int value = count-n;
//     int count1=0;
//     while(head != NULL)
//     {
//         if(count1 == value)
//             return head->data;
//         count1++;
//         head = head->next;
//     }
//     return -1;
    if(head == NULL)
        return;
    Node *first = head;
    for(int i=0;i<n;i++)
    {
        if(first == NULL)
            return;
        first = first->next;
    }
    Node *second = head;
    while(first != NULL)
    {
        second = second->next;
        first = first->next;
    }
    cout<<second->data;
}
