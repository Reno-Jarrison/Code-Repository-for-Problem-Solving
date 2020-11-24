#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
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
ll inv(ll x)
{	return qpow(x,mod-2); }
ll a[maxn],b[maxn],p[maxn];
int main()
{
	int n; ll inv100=inv(100);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
		scanf("%lld",&p[i]);
	a[n]=(100-p[n])*inv100%mod,b[n]=1;
	for(int i=n-1;i;i--)
	{
		a[i]=a[i+1]*p[i]%mod*inv100%mod;
		a[i]=(a[i]+(100-p[i])*inv100%mod)%mod;
		b[i]=(b[i+1]*p[i]%mod*inv100%mod+1)%mod;
	}
	printf("%lld",b[1]*inv((1-a[1]+mod)%mod)%mod);
}