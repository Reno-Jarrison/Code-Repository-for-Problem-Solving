#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
ll qpow(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%mod;
		a=a*a%mod,b>>=1;
	}
	return ans;
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		ll a,r,cur=1,ans=0;
		scanf("%d%lld%lld",&n,&a,&r);
		for(int i=1;i<=n;i++)
		{
			cur=cur*a%mod;
			ans=(ans+cur*qpow(i,r)%mod)%mod;
		}
		printf("%lld\n",ans);
	}
}