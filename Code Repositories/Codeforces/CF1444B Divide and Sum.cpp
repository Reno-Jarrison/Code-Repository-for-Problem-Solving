#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=3e5+5,mod=998244353;
ll a[maxn],fac[maxn],invf[maxn];
ll qpow(ll a,ll b,ll p=mod)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%p;
		a=a*a%p,b>>=1;
	}
	return ans;
}
ll C(int n,int m)
{	return fac[n]*invf[m]%mod*invf[n-m]%mod; }
void init(int n)
{
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%mod;
	invf[n]=qpow(fac[n],mod-2);
	for(int i=n-1;~i;i--)
		invf[i]=invf[i+1]*(i+1)%mod;
}
int main()
{
	init(3e5);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+2*n+1);
	ll sum=0;
	for(int i=1;i<=n;i++)
		sum=(sum+abs(a[i]-a[i+n]))%mod;
	printf("%lld\n",sum*C(2*n,n)%mod);
}