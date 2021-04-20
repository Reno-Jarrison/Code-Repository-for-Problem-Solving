#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e7+5,mod=1e9+7;
int tot,p[maxn],vis[maxn],mnp[maxn];
void init(int n)
{
	mnp[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i]) mnp[i]=p[++tot]=i;
		for(int j=1;i*p[j]<=n;j++)
		{
			vis[i*p[j]]=1,mnp[i*p[j]]=p[j];
			if(i%p[j]==0) break;
		}
	}
}
int main()
{
	init(1e7);
	int n,m,l,r;
	scanf("%d%d",&l,&r);
	n=r-l+1,m=(l==1);
	for(int i=l;i<=r;i++)
		if(i/mnp[i]<l) m++;
	ll ans=m;
	for(int i=1;i<=n+1;i++)
		if(i!=m+1) ans=ans*i%mod;
	printf("%lld\n",ans);
}