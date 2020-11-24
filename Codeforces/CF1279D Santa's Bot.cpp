#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5;
const ll mod=998244353;
ll p[maxn],d[maxn],ans;
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
	int n,a,k;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		for(int i=1;i<=k;i++)
			cin>>a,p[a]=(p[a]+inv(k))%mod,d[a]++;
	}
	for(int i=1;i<=maxn-5;i++)
		ans=(ans+p[i]*inv(n)%mod*(n-d[i])%mod*inv(n)%mod)%mod;
	printf("%lld",((1-ans)%mod+mod)%mod);
}