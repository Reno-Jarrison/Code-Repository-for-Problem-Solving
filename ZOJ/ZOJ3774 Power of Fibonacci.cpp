#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=1e9+9;
const int maxn=1e5+5;
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
ll getinv(ll x)
{	return qpow(x,mod-2); }
ll an[maxn],bn[maxn],sn[maxn],fac[maxn],inv[maxn];
void init(int n)
{
	ll a=691504013;
	ll b=308495997;
	ll s=276601605;
	an[0]=bn[0]=sn[0]=fac[0]=1;
	for(int i=1;i<=n;i++) sn[i]=sn[i-1]*s%mod;
	for(int i=1;i<=n;i++) an[i]=an[i-1]*a%mod;
	for(int i=1;i<=n;i++) bn[i]=bn[i-1]*b%mod;
	for(int i=1;i<=n;i++) fac[i]=fac[i-1]*i%mod;
	inv[n]=getinv(fac[n]);
	for(int i=n-1;~i;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
ll C(int n,int m)
{	return fac[n]*inv[m]%mod*inv[n-m]%mod; }
int main()
{
	init(1e5+3);
	int t,k;
	ll n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%d",&n,&k);
		ll ans=0;
		for(int i=0;i<=k;i++)
		{
			ll q=an[k-i]*bn[i]%mod;
			ll sum=q==1?n%mod:q*(qpow(q,n)-1+mod)%mod*getinv(q-1)%mod;
			if(!(i&1)) ans=(ans+sum*C(k,i)%mod)%mod;
			else ans=(ans-sum*C(k,i)%mod+mod)%mod;
		}
		ans=sn[k]*ans%mod;
		printf("%lld\n",ans);
	}
}