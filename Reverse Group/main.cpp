#include <iostream>

using namespace std;

int main()
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;
    int k;
    cout<<"Enter group size: ";
    cin>>k;
    int arr[n];
    cout<<"Enter array Elements :-\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<n;i+=k)
    {
        if((i+k)<=n)
        {
            for(int j=0;j<k/2;j++)
            {
                int temp=arr[j+i];
                arr[j+i]=arr[i+k-1-j];
                arr[i+k-1-j]=temp;
            }
        }
        else
            for(int j=0;j<(n-i)/2;j++)
            {
                int temp=arr[j+i];
                arr[j+i]=arr[n-1-j];
                arr[n-1-j]=temp;
            }
    }
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
