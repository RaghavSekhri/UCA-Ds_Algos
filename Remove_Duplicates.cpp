#include<iostream>                
using namespace std;
int main()
{
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array : ";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int j=0;
    for(int i=1;i<n;i++)
    {
        if(arr[i]!=arr[j])
        {
            j++;
            arr[j]=arr[i];
        }
    }
    cout<<"No. of unique elements are : "<<j+1<<"\n";
    return 0;
}

