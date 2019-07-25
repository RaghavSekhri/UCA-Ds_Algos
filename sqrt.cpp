#include<iostream>
using namespace std;
int main()
{
int n;
cout<<"Enter the number whose square root you have to find : ";
cin>>n;
int mid,l=1,r=n;
int lb,ans;
while(l<r)
{
	mid=(l+r)/2;
	if((mid)*(mid)<=n)
	{
		l=mid+1;
		ans=mid;
	}
	else
		r=mid-1;
}
cout<<"The floor value of square root : "<<ans<<"\n";
return 0;
}

