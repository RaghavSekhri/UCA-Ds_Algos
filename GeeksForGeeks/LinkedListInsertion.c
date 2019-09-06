Node *insertAtBegining(Node *head, int newData) {
    Node *temp = (Node*) malloc (sizeof(Node));
    temp->data = newData;
    temp->next = head;
    head = temp;
    return head;
}
// function appends the data at the end of the list
Node *insertAtEnd(Node *head, int newData)  {
    Node *temp = (Node*) malloc (sizeof(Node));
    Node *temp1;
    temp->data = newData;
    temp->next = NULL;
    if(head==NULL)
    {
        head = temp;
        return head;
    }
    temp1 = head;
    while(temp1->next != NULL)
        temp1 = temp1->next;
    temp1->next = temp;
    return head;
}