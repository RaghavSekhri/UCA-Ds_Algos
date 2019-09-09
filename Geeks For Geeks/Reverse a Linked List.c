Node* reverseList(Node *head)
{
  Node *curr,*prev,*next;
  curr = head;
  prev = NULL;
  next = NULL;
  while(curr != NULL)
  {
      next = curr->next;
      curr->next = prev;
      prev = curr;
      curr = next;
  }
  head = prev;
  return head;
}