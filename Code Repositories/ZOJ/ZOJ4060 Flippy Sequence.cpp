#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5;
char a[maxn],b[maxn];
int x[maxn];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%s%s",&n,a,b);
		for(int i=0;i<n;i++)
			x[i]=(a[i]!=b[i]);
		int tag=0,tot=0;
		x[n]=0;
		for(int i=0;i<=n;i++)
			if(x[i]) tag=1;
			else if(!x[i]&&tag)
				tot++,tag=0;
		ll ans=0;
		if(tot==0) ans=1LL*n*(n+1)/2;
		if(tot==1) ans=n*2-2;
		if(tot==2) ans=6;
		printf("%lld\n",ans);
	}
}