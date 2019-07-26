#include<iostream>                              //maximum occurrence
using namespace std;
int main()
{
    int n,m=0,p=0,l=0;
    cout<<"Enter size of array:";
    cin>>n;
    int arr1[n],arr2[n];
    cout<<"Enter elements of first array:";
    for(int i=0;i<n;i++)
       {
           cin>>arr1[i];
           if(arr1[i]>l)
            l=arr1[i];
       }
    cout<<"Enter elements of second array:";
    for(int i=0;i<n;i++)
       {
           cin>>arr2[i];
           if(arr2[i]>l)
            l=arr2[i];
       }
    int a[l+2]={0},x=0;
    for(int i=0;i<n;i++)
    {
        a[arr1[i]]++;
        a[arr2[i]+1]--;
    }
    for(int i=0;i<=l+1;i++)
    {
        if(p+a[i]>m)
           {
               m=p+a[i];
               x=i;
           }
        p=p+a[i];
    }
cout<<endl<<"The maximum occurred element is : "<<x<<"\n";
    return 0;
}

