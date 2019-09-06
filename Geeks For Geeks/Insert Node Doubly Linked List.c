void addNode(Node *head, int pos, int data)
{
    int count=0;
    Node *temp = (Node*) malloc (sizeof(Node));
    temp->data = data;
    while(head != NULL)
    {
        if(count == pos)
        {
            temp->next = head->next;
            temp->prev = head;
            head->next = temp;
        }
        count++;
        head = head->next;
    }
}