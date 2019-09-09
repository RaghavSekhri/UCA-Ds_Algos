Node* rotate(Node* head, int k) {
    Node *temp = head;
    Node *temp1 = head;
    while(temp->next != NULL)
        temp = temp->next;
    if(k==1)
        temp->next = temp1;
    else
    {
        for(int i=0;i<k-1;i++)
        {
            temp->next = temp1;
            temp1 = temp1->next;
            temp = temp->next;
        }
    }
    head = temp1->next;
    temp1->next = NULL;
    return head;
}