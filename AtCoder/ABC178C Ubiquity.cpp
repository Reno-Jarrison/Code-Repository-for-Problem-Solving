#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+7;
ll qpow(ll a,ll b,ll p=mod)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%p;
		a=a*a%p,b>>=1;
	}
	return ans;
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%lld\n",(qpow(10,n)-2LL*qpow(9,n)+qpow(8,n)+mod*2)%mod);
}