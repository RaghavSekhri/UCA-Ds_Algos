bool isPalindrome(Node *head)
{
Node *p;
    p=head;
    int t1=0,t2=0,n=1;
    while(p!=NULL)
    {
        t1=t1+(p->data*n);
        t2=(t2*10)+p->data;
        p=p->next;
        n=n*10;
    }
    if(t1==t2)
        return 1;
    else
        return 0;
}