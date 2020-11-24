#include<bits/stdc++.h>
#define ll long long
#define mod 200907
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
void exgcd(ll a,ll b,ll& x,ll& y)
{
	if(!b) x=1,y=0;
	else exgcd(b,a%b,y,x),y-=a/b*x;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll a,b,c,k,ans;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&k);
		if(a+c==b<<1) ans=(a+(b-a)*(k-1)%mod)%mod;
		else
		{
			ll q=b/a%mod;
			ans=a*qpow(q,k-1)%mod;
		}
		printf("%lld\n",ans);
	}
}