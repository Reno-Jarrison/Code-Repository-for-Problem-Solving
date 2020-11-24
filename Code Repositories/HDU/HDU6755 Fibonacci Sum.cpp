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
ll a=691504013,b=308495997,inva=getinv(a);
ll sn[maxn],fac[maxn],inv[maxn];
void init(int n)
{
	ll s=276601605;
	sn[0]=fac[0]=1;
	for(int i=1;i<=n;i++) sn[i]=sn[i-1]*s%mod;
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
	ll n,c;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%d",&n,&c,&k);
		ll ans=0,cmod=c%(mod-1);
		ll d=qpow(inva,cmod)*qpow(b,cmod)%mod;
		ll q=qpow(qpow(a,cmod),k);
		ll nmod1=(n+1)%mod,nmod2=(n+1)%(mod-1);
		for(int i=0;i<=k;i++)
		{
			ll sum=q==1?nmod1:(1-qpow(q,nmod2)+mod)*getinv(1-q+mod)%mod;
			if(i&1) sum=mod-sum;
			ans=(ans+sum*C(k,i)%mod)%mod;
			q=q*d%mod;
		}
		ans=sn[k]*ans%mod;
		printf("%lld\n",ans);
	}
}