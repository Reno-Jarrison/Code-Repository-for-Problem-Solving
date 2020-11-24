#include<cstdio>
#define ll long long
const ll mod=1e9+7;
using namespace std;
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
	ll n,k,ks=0;
	while(~scanf("%lld%lld",&n,&k))
		printf("Case #%lld: %lld\n",++ks,qpow(n%mod,k));
}