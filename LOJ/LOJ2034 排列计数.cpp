#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5,mod=1e9+7;
ll d[maxn],fac[maxn],invf[maxn];
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
void solve(int n)
{
	fac[0]=d[0]=1,d[1]=0;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%mod;
	for(int i=2;i<=n;i++)
		d[i]=(d[i-1]+d[i-2])*(i-1)%mod;
	invf[n]=qpow(fac[n],mod-2);
	for(int i=n-1;~i;i--)
		invf[i]=invf[i+1]*(i+1)%mod;
}
ll C(int n,int m)
{	return fac[n]*invf[m]%mod*invf[n-m]%mod; }
int main()
{
	solve(1e6);
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		if(m>n) puts("0");
		else printf("%lld\n",C(n,m)*d[n-m]%mod);
	}
}