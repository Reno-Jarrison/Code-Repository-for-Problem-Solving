#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e4+5;
int pcnt,prime[maxn],vis[maxn],mu[maxn],sum[maxn],n;
void shift(int n)
{
	mu[1]=sum[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i]) prime[++pcnt]=i,mu[i]=-1;
		for(int j=1;i*prime[j]<=n;j++)
		{
			vis[i*prime[j]]=1;
			if(i%prime[j]==0) break;
			else mu[i*prime[j]]=-mu[i];
		}
		sum[i]=sum[i-1]+mu[i];
	}
}
ll divblock(ll n,ll m)
{
	ll ans=0;
	if(n>m) swap(n,m);
	for(ll l=1,r;l<=n;l=r+1)
	{
		r=min(n/(n/l),m/(m/l));
		ans+=(n/l)*(m/l)*(sum[r]-sum[l-1]);
	}
	return ans;
}
int main()
{
	shift(maxn-5);
	scanf("%d",&n);
	while(n--)
	{
		ll a,b,d;
		scanf("%lld%lld%lld",&a,&b,&d);
		a/=d,b/=d;
		printf("%lld\n",divblock(a,b));
	}
}
