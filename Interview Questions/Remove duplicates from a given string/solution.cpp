// C++ program too create a unique string using unordered_map 
  
/* access time in unordered_map on is O(1) generally if no collisions occur  
and therefore it helps us check if an element exists in a string in O(1)  
time complexity with constant space. */
  
#include <bits/stdc++.h>  
using namespace std;  
char* removeDuplicates(char *s,int n){ 
  unordered_map<char,int> exists; 
  int index = 0;  
  for(int i=0;i<n;i++){ 
    if(exists[s[i]]==0) 
    { 
      s[index++] = s[i]; 
      exists[s[i]]++; 
    } 
  } 
  return s; 
} 
  
//driver code 
int main(){ 
  char s[] = "geeksforgeeks"; 
  int n = sizeof(s)/sizeof(s[0]); 
  cout<<removeDuplicates(s,n)<<endl; 
  return 0; 
} 