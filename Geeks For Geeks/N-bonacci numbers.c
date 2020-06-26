// CPP program print first M terms of 
// N-bonacci series. 
#include <bits/stdc++.h> 
using namespace std; 

// Function to print bonacci series 
void bonacciseries(long n, int m) 
{ 

	// Assuming m > n. 
	int a[m] = { 0 }; 
	a[n - 1] = 1; 
	a[n] = 1; 

	// Uses sliding window 
	for (int i = n + 1; i < m; i++) 
		a[i] = 2 * a[i - 1] - a[i - n - 1]; 

	// Printing result 
	for (int i = 0; i < m; i++) 
		cout << a[i] << " "; 
} 

// Driver's Code 
int main() 
{ 
	int N = 5, M = 15; 
	bonacciseries(N, M); 
	return 0; 
} 
