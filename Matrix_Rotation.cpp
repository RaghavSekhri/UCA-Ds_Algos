#include<iostream>           //rotation of matrix by 90 degrees
using namespace std;
int main()
{
    int n;
    cout<<"Enter size of matrix : ";
    cin>>n;
    int arr[n][n];
    cout<<"Enter elements of matrix : ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }
    for(int i=0;i<n/2;i++)
    {
        for(int j=i;j<n-1-i;j++)
        {
            int temp=arr[i][j];
            arr[i][j]=arr[n-1-j][i];
            arr[n-1-j][i]=arr[n-1-i][n-1-j];
            arr[n-1-i][n-1-j]=arr[j][n-1-i];
            arr[j][n-1-i]=temp;
        }
    }
    cout<<"The rotated array is :- "<<"\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
