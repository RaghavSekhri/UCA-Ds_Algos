Node *removeDuplicates(Node *root)
{
    Node *temp = root;
    while(temp != NULL && temp->next != NULL)
    {
        if(temp->data == temp->next->data)
            temp->next = temp->next->next;
        else
            temp = temp->next;
    }
    return root;
}