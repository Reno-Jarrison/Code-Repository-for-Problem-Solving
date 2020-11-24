#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int tot,prime[maxn],vis[maxn];
void init(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!vis[i]) prime[++tot]=i;
		for(int j=1;i*prime[j]<=n;j++)
		{
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
}
void update(ll& ans,ll src,ll pf,ll mul)
{	
	while(src%pf==0) src/=pf;
	ans=max(ans,src*mul);
}
int main()
{
	init(1e5);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll p,q;
		scanf("%lld%lld",&p,&q);
		if(p%q)
		{	printf("%lld\n",p); continue; }
		ll ans=1,tmp=q;
		for(int i=1;tmp>1&&prime[i]*prime[i]<=tmp;i++)
			if(tmp%prime[i]==0) 
			{
				ll cur=1;
				while(tmp%prime[i]==0) cur*=prime[i],tmp/=prime[i];
				update(ans,p,prime[i],cur/prime[i]);
			}
		if(tmp>1) update(ans,p,tmp,1);
		printf("%lld\n",ans);
	}
}