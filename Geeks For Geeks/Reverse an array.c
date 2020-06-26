#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int n)
{
    for(int i = 0; i < n/2; i++)
     swap(arr[i], arr[n-i-1]);
}

int main()
{
    int arr[] = {2, 8, 7, 10, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    reverse(arr, n);
    for(int i = 0; i < n; i++)
      cout << arr[i] << " ";
    return 0;
}