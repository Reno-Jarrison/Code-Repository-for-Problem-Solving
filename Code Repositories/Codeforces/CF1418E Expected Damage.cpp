#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
const ll mod=998244353;
ll d[maxn],pre[maxn];
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
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&d[i]);
	sort(d+1,d+n+1);
	for(int i=1;i<=n;i++)
		pre[i]=(pre[i-1]+d[i])%mod;
	while(m--)
	{
		ll a,b;
		scanf("%lld%lld",&a,&b);
		int cntl=lower_bound(d+1,d+n+1,b)-d-1,cntr=n-cntl;
		if(cntr<a) puts("0");
		else
		{
			ll suml=pre[cntl],sumr=(pre[n]-pre[cntl]+mod)%mod;
			ll ans1=(1-a*inv(cntr+1)%mod+mod)%mod*suml%mod;
			ll ans2=(1-a*inv(cntr)%mod+mod)%mod*sumr%mod;
			printf("%lld\n",(ans1+ans2)%mod);
		}
	}
}