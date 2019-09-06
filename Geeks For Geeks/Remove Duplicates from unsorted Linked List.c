Node *removeDuplicates(Node *root)
{
    Node *p1,*p2,*dup;
    p1 = root;
    while(p1 != NULL && p1->next != NULL)
    {
        p2 = p1;
        while(p2 != NULL && p2->next != NULL)
        {
            if(p1->data == p2->next->data)
            {
                dup = p2->next;
                p2->next = p2->next->next;
                free(dup);
            }
            else
                p2 = p2->next;
        }
        p1 = p1->next;
    }
    return root;
}