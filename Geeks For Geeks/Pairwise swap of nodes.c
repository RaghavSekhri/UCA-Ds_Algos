struct Node* pairwise_swap(struct Node* head)
{
    if(head == NULL || head->next == NULL)
       return NULL;
    struct Node *prev = head; 
    struct Node *curr = head->next; 
    head = curr; 
    while (true) 
    { 
        struct Node *next = curr->next; 
        curr->next = prev;
        if (next == NULL || next->next == NULL) 
        { 
            prev->next = next; 
            break; 
        } 
        prev->next = next->next; 
        prev = next; 
        curr = prev->next; 
    } 
    
    return head;
}