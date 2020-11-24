#include<bits/stdc++.h>
using namespace std;
int a[305][305];
int sqr(int x)
{	return x*x; }
int main()
{
	int t,n,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		memset(a,0,sizeof(a));
		for(int i=0;i<n&&k;i++)
			for(int j=0;j<n&&k;j++)
				a[(i+j)%n][j]=1,k--;
		int rmax=0,rmin=n;
		for(int i=0;i<n;i++)
		{
			int cnt=0;
			for(int j=0;j<n;j++)
				cnt+=a[i][j];
			rmax=max(rmax,cnt);
			rmin=min(rmin,cnt);
		}
		int cmax=0,cmin=n;
		for(int i=0;i<n;i++)
		{
			int cnt=0;
			for(int j=0;j<n;j++)
				cnt+=a[j][i];
			cmax=max(cmax,cnt);
			cmin=min(cmin,cnt);
		}
		cout<<sqr(rmax-rmin)+sqr(cmax-cmin)<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				cout<<a[i][j];
			cout<<endl;
		}
	}
}