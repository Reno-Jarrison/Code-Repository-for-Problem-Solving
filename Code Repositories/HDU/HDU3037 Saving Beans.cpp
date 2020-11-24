#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
ll fac[maxn];
ll qpow(ll a,ll b,ll p)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%p;
		a=a*a%p,b>>=1;
	}
	return ans;
}
ll inv(int x,int p)
{	return qpow(x,p-2,p); }
ll c(int n,int m,int p)
{	return m>n?0:fac[n]*inv(fac[m],p)%p*inv(fac[n-m],p)%p; }
ll lucas(int n,int m,int p)
{	return m?lucas(n/p,m/p,p)*c(n%p,m%p,p)%p:1; }
void solve(int n,int p)
{
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%p;
}
int main()
{
	int t,n,m,p;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&p);
		solve(p,p);
		printf("%lld\n",lucas(n+m,n,p));
	}
}