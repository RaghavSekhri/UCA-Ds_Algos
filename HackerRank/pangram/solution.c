#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

int checkPangram (char str[]) 
{ 
    int mark[26] = {0};
    int index; 
    for (int i=0; str[i]!='\0'; i++) 
    { 
        if ('A' <= str[i] && str[i] <= 'Z') 
            index = str[i] - 'A'; 
        else if('a' <= str[i] && str[i] <= 'z') 
            index = str[i] - 'a'; 
        mark[index] = true; 
    } 
    for (int i=0; i<26; i++) 
        if (mark[i] == false) 
            return 0; 
    return 1; 
} 
int main() {
    int n,m;
    scanf("%d",&n);
    char ch[n][100000];
    for(m=0;m<n;m++)
    {
        scanf(" %[^\n]",ch[m]);
        int x= checkPangram(ch[m]);
        printf("%d",x);
    }
  return 0;
}