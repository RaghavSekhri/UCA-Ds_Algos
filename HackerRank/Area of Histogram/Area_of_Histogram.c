#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

typedef struct stack
{
int data;
struct stack* next;

}st;

st* s;
int max=0;

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

int getMaxArea(int* hist, int n){
    for(int i=0;i<n;i++)
    {
        if(empty(s) || hist[i] >= hist[peek(s)])
        push(&s, i);
        else
        {
            while(!empty(s) && hist[peek(s)] > hist[i])
            {
                int x = hist[peek(s)];
                pop(&s);
                int distance = empty(s) ? i :(i - peek(s) - 1);
                int area = distance * x;
                if(area > max)
                    max = area;
            }
            push(&s, i);
        }
    }
    while(!empty(s))
    {
        int x = hist[peek(s)];
        pop(&s);
        int distance = empty(s) ? n : (n - peek(s) - 1);
        int area = distance * x;
        if(area > max)
            max = area;
    }
    return max;
}


int main() {
   
    int n;
    scanf("%d", &n);
    int arr[n];
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
        
    }
    
    int r = getMaxArea(arr, n);
    printf("%d", r);
    return 0;
}


