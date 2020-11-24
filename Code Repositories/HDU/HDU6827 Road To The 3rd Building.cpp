#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=4e5+5;
const ll mod=1e9+7;
int s[maxn];
ll fac[maxn],finv[maxn],inv[maxn],sinv[maxn];
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
void init(int n)
{
	inv[1]=1;
	for(int i=2;i<=n;i++)
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=n;i++)
		sinv[i]=(sinv[i-1]+inv[i])%mod;
}
int main()
{
	init(4e5);
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&s[i]);
		ll ans=0,pre=0,tot=(1LL*n*(n-1)%mod*qpow(2,mod-2)+n)%mod;
		for(int i=1;i<=n;i++)
		{
			pre=(pre-sinv[n]+sinv[n-i+1]+mod)%mod;
			pre=(pre+sinv[n]-sinv[i-1]+mod)%mod;
			ans=(ans+pre*s[i])%mod;
		}
		ans=ans*qpow(tot,mod-2)%mod;
		printf("%lld\n",ans);
	}
}