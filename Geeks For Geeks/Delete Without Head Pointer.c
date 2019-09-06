void deleteNode(Node *node)
{
    if (node == NULL) 
        return; 
    else 
    { 
        if (node->next == NULL)
            return; 
        node->data = node->next->data; 
        node->next = node->next->next; 
    }
}