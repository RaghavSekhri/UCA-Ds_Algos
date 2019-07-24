#include<iostream>
using namespace std;
int main()
{
	int m,n;
	cout<<"Enter size of first array : ";
	cin>>m;
	cout<<"Enter size of second array : ";
	cin>>n;
	int min;
	min=(m<n)?m:n;
	int a[m],b[n],res[min];
	cout<<"Enter elements of first array :- "<<"\n";
	for(int i=0;i<m;i++)
		cin>>a[i];
	cout<<"Enter elements of second array :- "<<"\n";
	for(int i=0;i<n;i++)
		cin>>b[i];
	int i=0,j=0,k=0;
	while(i<m && j<n)
	{
		if(a[i]<b[j])
			i++;
		else
		if(a[i]>b[j])
			j++;
		else
		{
			res[k]=a[i];
			i++;
			j++;
			k++;
		}
	}
	cout<<"Intersecting elements are :- "<<"\n";
	for(int l=0;l<k;l++)
		cout<<res[l]<<" ";
	cout<<"\n";
	return 0;
}
