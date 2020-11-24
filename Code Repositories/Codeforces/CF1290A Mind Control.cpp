#include<bits/stdc++.h>
using namespace std;
const int maxn=3505,inf=0x3f3f3f3f;
int a[maxn];
int main()
{
	int t,n,m,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>k;
		for(int i=1;i<=n;i++) cin>>a[i];
		k=min(k,m-1),m-=k+1;
		int ans=0;
		for(int i=0;i<=k;i++)
		{
			int l=i+1,r=n-(k-i),mnv=inf;
			for(int j=0;j<=m;j++)
			{
				int lx=l+j,rx=r-(m-j);
				mnv=min(mnv,max(a[lx],a[rx]));
			}
			ans=max(ans,mnv);
		}
		cout<<ans<<endl;
	}
}