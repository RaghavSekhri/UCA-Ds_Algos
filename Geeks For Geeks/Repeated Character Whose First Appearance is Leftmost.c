// CPP program to find first repeating 
// character 
#include <bits/stdc++.h> 
using namespace std; 
#define NO_OF_CHARS 256 
  
/* The function returns index of the first  
repeating character in a string. If  
all characters are repeating then  
returns -1 */
int firstRepeating(string& str) 
{ 
    // Mark all characters as not visited 
    bool visited[NO_OF_CHARS]; 
    for (int i = 0; i < NO_OF_CHARS; i++) 
        visited[i] = false; 
  
    // Traverse from right and update res as soon 
    // as we see a visited character. 
    int res = -1; 
    for (int i = str.length() - 1; i >= 0; i--) { 
        if (visited[str[i]] == false) 
            visited[str[i]] = true; 
        else
            res = i; 
    } 
  
    return res; 
} 
  
/* Driver program to test above function */
int main() 
{ 
    string str = "geeksforgeeks"; 
    int index = firstRepeating(str); 
    if (index == -1) 
        printf("Either all characters are "
               "distinct or string is empty"); 
    else
        printf("First Repeating character"
               " is %c", 
               str[index]); 
    return 0; 
} 