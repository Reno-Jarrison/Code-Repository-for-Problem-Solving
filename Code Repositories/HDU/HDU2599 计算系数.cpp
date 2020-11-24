#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e4+5,mod=10007;
ll fac[maxn]={1,1},inv[maxn]={1};
ll qpow(ll a,ll b,ll p)
{
	ll ans=1;
	while(b)
	{
		if(b&1) (ans*=a)%=p;
		(a*=a)%=p,b>>=1;
	}
	return ans;
}
int main()
{
	int a,b,k,n,m;
	scanf("%d%d%d%d%d",&a,&b,&k,&n,&m);
	ll ans=qpow(a,n,mod)*qpow(b,m,mod)%mod;
	for(int i=2;i<=k;i++) fac[i]=fac[i-1]*i%mod;
	inv[k]=qpow(fac[k],mod-2,mod);
	for(int i=k-1;i;i--) inv[i]=inv[i+1]*(i+1)%mod;
	if(n<m) swap(n,m);
	ans=ans*fac[k]%mod*inv[n]%mod*inv[k-n]%mod;
	printf("%lld",ans);
}