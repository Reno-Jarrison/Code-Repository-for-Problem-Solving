#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int maxn=1e6+5;
int tot,p[maxn],vis[maxn];
void sieve(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!vis[i]) p[++tot]=i;
		for(int j=1;i*p[j]<=n;j++)
		{
			vis[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
}
ll solve(ll n,ll p)
{
	ll ans=0;
	while(n) n/=p,ans+=n;
	return ans;
}
int main()
{
	int t;
	ll n,k;
	sieve(1e6);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		ll ans=1e18;
		for(int i=1;1LL*p[i]*p[i]<=k&&i<=tot;i++)
			if(k%p[i]==0)
			{
				int cnt=0;
				while(k%p[i]==0) k/=p[i],cnt++;
				ans=min(ans,solve(n,p[i])/cnt);
			}
		if(k>1) ans=min(ans,solve(n,k));
		printf("%lld\n",ans);
	}
}