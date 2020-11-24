#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e6+5,mod=998244353;
int ans[maxn],fac[maxn],invf[maxn],powi[maxn];
int qpow(ll a,ll b)
{
	int ans=1;
	while(b)
	{
		if(b&1) ans=(ll)ans*a%mod;
		a=(ll)a*a%mod,b>>=1;
	}
	return ans;
}
void init(int n)
{
	fac[0]=powi[0]=1;
	powi[1]=qpow(2,mod-2);
	for(int i=1;i<=n;i++)
	{
		fac[i]=(ll)fac[i-1]*i%mod;
		powi[i]=(ll)powi[i-1]*powi[1]%mod;
	}
	invf[n]=qpow(fac[n],mod-2);
	for(int i=n-1;~i;i--)
		invf[i]=(ll)invf[i+1]*(i+1)%mod;
}
ll C(int n,int m)
{	return (ll)fac[n]*invf[m]%mod*invf[n-m]%mod; }
int main()
{
	init(maxn);
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int mid=n/2,sum=0;
		for(int i=1;i<=mid;i++) ans[i]=0;
		for(int i=mid+1;i<=n;i++)
		{
			int pre=i-1,suc=n-i,res=pre-suc;
			ans[i]=(ll)C(pre,suc)*fac[suc]%mod;
			ans[i]=(ll)ans[i]*fac[res]%mod*powi[res/2]%mod*invf[res/2]%mod;
			sum=(sum+ans[i])%mod;
		}
		int invs=qpow(sum,mod-2);
		for(int i=mid+1;i<=n;i++)
			ans[i]=(ll)ans[i]*invs%mod;
		for(int i=1;i<=n;i++)
			printf("%d%c",ans[i],i==n?'\n':' ');
	}
}