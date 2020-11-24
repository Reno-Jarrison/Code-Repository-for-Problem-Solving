#include<iostream>
using namespace std;
int a[200005];
int main()
{
	int t,n,k,d,l;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		d=0x3fffffff,l=0;
		for(register int i=1;i<=n;i++)
			cin>>a[i];
		for(register int pt=1;pt+k<=n;pt++)
		{
			int dist=a[pt+k]-a[pt];
			if(dist<d)
				d=dist,l=a[pt];
		}
		cout<<l+d/2<<endl;
	}
}
