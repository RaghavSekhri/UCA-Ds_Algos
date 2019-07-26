#include<iostream>                  //making the rows and columns of a matrix to zero which initially contains zero
using namespace std;
int main()
{
    int n,r=1,c=1;
    cout<<"Enter size of array : ";
    cin>>n;
    int arr[n][n];
    cout<<"Enter elements of array : ";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }
    for(int i=0;i<n;i++)
    {
        if(arr[0][i]==0)
            r=0;
        if(arr[i][0]==0)
            c=0;
    }
    if(arr[1][1]==0)
    {
        arr[0][1]=0;
        arr[1][0]=0;
    }
    for(int i=1;i<n;i++)
    {
        if(arr[0][i]==0)
        {
            for(int j=1;j<n;j++)
                arr[j][i]=0;
        }
        if(arr[i][0]==0)
        {
            for(int j=1;j<n;j++)
                arr[i][j]=0;
        }
    }
    if(r==0)
    {
        for(int i=0;i<n;i++)
            arr[0][i]=0;
    }
    if(c==0)
    {
        for(int i=0;i<n;i++)
            arr[i][0]=0;
    }
    cout<<"Modified matrix is :- "<<"\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

