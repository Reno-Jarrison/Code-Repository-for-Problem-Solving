#include<bits/stdc++.h>
#define ll long long 
#define LL __int128
using namespace std;
ll prime[10]={2,3,5,7,11,13,17,19,23,29};
ll qmul(ll a,ll b,ll p)
{	return (ll)((LL)a*b%p); }
ll qpow(ll a,ll b,ll p)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=qmul(ans,a,p);
		a=qmul(a,a,p),b>>=1;
	}
	return ans;
}
ll inv(ll a,ll p)
{	return qpow(a,p-2,p); }
bool mr(ll x)
{
	if(x==1) return false;
	for(int i=0;i<10;i++)
	{
		if(x==prime[i]) return true;
		if(x<prime[i]) return false;
		ll tnp=x-1,tmp=qpow(prime[i],tnp,x);
		if(tmp!=1) return false;
		while(tmp==1&&!(tnp&1))
		{
			tmp=qpow(prime[i],tnp>>=1,x);
			if(tmp!=1&&tmp!=x-1) return false;
		}
	}
	return true;
}
int main(void)
{
	ll t,p,x,mul;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&p),x=p-2,mul=1;
		while(!mr(x)) 
			mul=qmul(mul,x--,p);
		printf("%lld\n",inv(mul,p));
	}
	return 0;
}