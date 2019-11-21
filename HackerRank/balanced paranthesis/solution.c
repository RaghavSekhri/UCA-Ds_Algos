#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include<stdio.h>
#define MAX 20
#define true 1
#define false 0
int top = -1;
int stack[MAX];
push(char);
char pop();
push(char item)
{
if(top == (MAX-1))
printf("Stack Overflow\n");
else
{
top=top+1;
stack[top] = item;
}
    return 0;
}/*End of push()*/
char pop()
{
if(top == -1)
printf("Stack Underflow\n");
else
return(stack[top--]);
    return 0;
}


int par(char *exp)
{
    int i,valid=true;
    char temp;
    for(i=0;i<strlen(exp);i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            push( exp[i] );
        if(exp[i]==')' || exp[i]=='}' || exp[i]==']')
            if(top == -1)    /* stack empty */
                valid=false;
            else
            {
                temp=pop();
                if( exp[i]==')' && (temp=='{' || temp=='[') )
                    valid=false;
                if( exp[i]=='}' && (temp=='(' || temp=='[') )
                    valid=false;
                if( exp[i]==']' && (temp=='(' || temp=='{') )
                    valid=false;
            }
    }
    if(top>=0) /*stack not empty*/
        valid=false;

    if( valid==true )
        printf("balanced");
    else
        printf("unbalanced");

        return 0;
}

int main()
{
char y[MAX],temp;

//printf("Enter an algebraic expression : ");
gets(y);
par(y);
return 0;
}