#include <bits/stdc++.h> 
using namespace std; 
  
void countFreq(int arr[], int n) 
{ 
    unordered_map<int, int> mp; 
  
    // Traverse through array elements and 
    // count frequencies 
    for (int i = 0; i < n; i++) 
        mp[arr[i]]++; 
  
    // To print elements according to first 
    // occurrence, traverse array one more time 
    // print frequencies of elements and mark 
    // frequencies as -1 so that same element 
    // is not printed multiple times. 
    for (int i = 0; i < n; i++) { 
      if (mp[arr[i]] != -1) 
      { 
          cout << arr[i] << " " << mp[arr[i]] << endl; 
          mp[arr[i]] = -1; 
      } 
    } 
} 
  
int main() 
{ 
    int arr[] = { 10, 20, 20, 10, 10, 20, 5, 20 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    countFreq(arr, n); 
    return 0; 
} 