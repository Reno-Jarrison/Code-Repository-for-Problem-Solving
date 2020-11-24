#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
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
	int t;
	scanf("%d",&t);
	ll n,x=3LL*qpow(2,mod-2)%mod;
	while(t--)
	{
		scanf("%lld",&n);
		ll ans=(qpow(2,n)+1+qpow(x,n)*2)%mod;
		printf("%lld\n",ans);
	}
}