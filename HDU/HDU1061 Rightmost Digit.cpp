#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll qpow(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%10;
		a=a*a%10,b>>=1;
	}
	return ans;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll n;
		scanf("%lld",&n);
		printf("%lld\n",qpow(n,n));
	}
}