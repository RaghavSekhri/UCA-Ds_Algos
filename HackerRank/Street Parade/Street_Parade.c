#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct stack{
    int data;
    struct stack* next;
}st;

st* s;

void push(st** top, int data)
{
    st* new = (st*)malloc(sizeof(st));
    
    new->data = data;
    new->next = *top;
    *top = new;
    
}

int peek(st* top)
{
    return top->data;
}

int empty(st* top)
{
    if(top==NULL)
    {
        return 1;
    }
    return 0;
}
void pop(st** top)
{
    
        st* temp=*top;
        *top=(*top)->next;
        free(temp);
        temp=NULL;    
}

void check(int *arr,int n){
    int flag=0;
    int a[n],r=0;
    for(int i=0;i<n;i++)
    {
        if(empty(s))
            push(&s, arr[i]);
        else
        {
            if(!empty(s) && arr[i] < peek(s))
                push(&s, arr[i]);
            else
            {
                while(!empty(s) && arr[i] > peek(s))
                {
                    a[r] = peek(s);
                    pop(&s);
                    r++;
                }
                push(&s, arr[i]);
            }     
        }
    }
    while(!empty(s))
    {
        a[r] = peek(s);
        pop(&s);
        r++;
    }
    for(int i=0;i<r-1;i++)
    {
        if(a[i+1] - a[i] == 1)
            flag=1;
        else
        {
            flag=0;
            break;
        }
    }
    if(a[0] != 1)
        printf("no");
    else
    {
    if(flag==0)
        printf("no");
    else
        printf("yes");
    }
}

int main() {
    int n;
    scanf("%d",&n);
    while(n!=0)
    {
        int *arr = (int*) malloc (sizeof(int)*n);
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        check(arr,n);
        scanf("%d",&n);
        if(n!=0)
            printf("\n");
    }
    return 0;
}


