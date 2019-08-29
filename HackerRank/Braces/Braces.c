#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();


// Complete the braces function below.

// Please store the size of the string array to be returned in result_count pointer. For example,
// char a[2][6] = {"hello", "world"};
//
// *result_count = 2;
//
// return a;
//

typedef struct node
{
    char data;
    struct node * next;
}node;
void push(node ** head,char value)
{
    node * newnode=(node*)malloc(sizeof(node));
    newnode->data=value;
    newnode->next=(*head);
    (*head)=newnode;
}
int empty(node * head)
{
    if(head==NULL)return 1;
    else return 0;
}
char top(node * head)
{
    if(head)
    return head->data;
    else return 'y';
}
void pop(node ** head)
{
    if((*head)!=NULL)
    {
        (*head)=(*head)->next;
    }
}
char** braces(int n, char** arr, int* result) 
{
    char ** res = (char**)malloc(n*sizeof(char*));
    int i=0,j=0,k=0;
    for(i=0;i<n;i++)
    {
        node *head= NULL;
        for(j=0;arr[i][j]!='\0';j++)
        {
            if(arr[i][j]=='(' || arr[i][j]=='[' || arr[i][j]=='{')
            {
                push(&head,arr[i][j]);
            }
            else
            {
                if(arr[i][j]=='}' && top(head)=='{')
                pop(&head);
                else{
                         if(arr[i][j]==')' && top(head)=='(')
                         pop(&head);
                    else
                    {
                          if(arr[i][j]==']' && top(head)=='[')
                          pop(&head);
                          else
                          push(&head,'x');
                    }
                }
            }
        }
        if(empty(head)==0)
        {
            res[k++]="NO";
        }
        else
        {
            res[k++]="YES";
        }
    }
    *result=n;
    return res;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* values_count_endptr;
    char* values_count_str = readline();
    int values_count = strtol(values_count_str, &values_count_endptr, 10);

    if (values_count_endptr == values_count_str || *values_count_endptr != '\0') { exit(EXIT_FAILURE); }

    char** values = malloc(values_count * sizeof(char*));

    for (int i = 0; i < values_count; i++) {
        char* values_item = readline();

        *(values + i) = values_item;
    }

    int res_count;
    char** res = braces(values_count, values, &res_count);

    for (int i = 0; i < res_count; i++) {
        fprintf(fptr, "%s", *(res + i));

        if (i != res_count - 1) {
            fprintf(fptr, "\n");
        }
    }

    fprintf(fptr, "\n");

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

