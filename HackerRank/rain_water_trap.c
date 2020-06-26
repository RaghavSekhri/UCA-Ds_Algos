#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int findWater(int arr[], int n) 
{ 
    int left[n]; 
    int right[n]; 
    int water = 0; 
    left[0] = arr[0]; 
    for (int i = 1; i < n; i++) 
        left[i] = max(left[i - 1], arr[i]); 
    right[n - 1] = arr[n - 1]; 
    for (int i = n - 2; i >= 0; i--) 
        right[i] = max(right[i + 1], arr[i]); 
    for (int i = 0; i < n; i++) 
        water += min(left[i], right[i]) - arr[i]; 
    return water; 
} 

int main() 
{ 
    int n;
    scanf("%d", &n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);
    printf("Maximum water that can be accumulated is %d", findWater(arr, n)); 
    return 0; 
}

//     -------OR-------

int trap(vector<int>& height)
{
    int ans = 0, current = 0;
    stack<int> st;
    while (current < height.size()) {
        while (!st.empty() && height[current] > height[st.top()]) {
            int top = st.top();
            st.pop();
            if (st.empty())
                break;
            int distance = current - st.top() - 1;
            int bounded_height = min(height[current], height[st.top()]) - height[top];
            ans += distance * bounded_height;
        }
        st.push(current++);
    }
    return ans;
}