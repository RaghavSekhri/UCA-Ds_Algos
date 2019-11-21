#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct sNode
 {
     char data;
     struct sNode* next;
 }stack;
 stack* s=NULL;
 void push(char new_data)
{
  stack* new_node = (stack*) malloc(sizeof(stack));
  new_node->data  = new_data;
  new_node->next = s;
  s=new_node;
}
int pop()
{
  stack *temp;
   int t;
   temp=s;
   t=temp->data;
   s=s->next;
   temp->next=NULL;
   free(temp);
     return t;
}
int isEmpty()
{
    if(s==NULL)
    return 1;
    else
    return 0;
}
int peek()
{
    if(s==NULL)
    return 0;
    else
    return s->data;
}
int Prec(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    }
    return -1;
}
int isOperand(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}
void infixToPostfix(char *exp)
{
    int i,k;
for (i = 0, k = -1; exp[i]; ++i)
    {
        if (isOperand(exp[i]))
            exp[++k] = exp[i];
        else if (exp[i] == '(')
            push(exp[i]);
        else if (exp[i] == ')')
        {
            while (!isEmpty() && peek() != '(')
                exp[++k] = pop();
            if (!isEmpty() && peek() != '(')
                return -1; 
            else
                pop();
        }
        else
        {
            while (!isEmpty() && Prec(exp[i]) <= Prec(peek()))
                exp[++k] = pop();
            push(exp[i]);
        }

    }
    while (!isEmpty())
        exp[++k] = pop();

    exp[++k] = '\0';
    printf( "%s", exp );
}
int main()
{
char exp[50];
 scanf("%s",exp);
    infixToPostfix(exp);
    return 0;
}