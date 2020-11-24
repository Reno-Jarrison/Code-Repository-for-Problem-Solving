#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5;
const ll mod=998244353;
int tot,p[maxn],vis[maxn];
ll num[maxn],sum[maxn];
void getprime(int n)
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
int main()
{
	getprime(1e6);
	int t;
	ll l,r,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&l,&r,&k);
		for(int i=0;i<=r-l;i++)
			num[i]=i+l,sum[i]=1LL;
		for(int i=1;1LL*p[i]*p[i]<=r;i++)
			for(ll j=max(2LL,(l+p[i]-1)/p[i])*p[i];j<=r;j+=p[i])
			{
				ll cnt=0;
				while(num[j-l]%p[i]==0)
					cnt++,num[j-l]/=p[i];
				sum[j-l]=sum[j-l]*(cnt*k%mod+1)%mod;
			}
		ll ans=0;
		for(int i=0;i<=r-l;i++)
		{
			if(num[i]>1) sum[i]=sum[i]*(k+1)%mod;
			ans=(ans+sum[i])%mod;
		}
		printf("%lld\n",ans);
	}
}
