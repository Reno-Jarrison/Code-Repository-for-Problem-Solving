#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e6+5;
const ll mod=1e6+3;
int tot,p[maxn],vis[maxn];
ll jd[maxn],ans[maxn];
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
void sieve(int n,int k)
{
	ans[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i]) p[++tot]=i,jd[i]=(qpow(i,k)-1+mod)%mod;
		for(int j=1;i*p[j]<=n;j++)
		{
			vis[i*p[j]]=1;
			if(i%p[j]==0) 
			{	jd[i*p[j]]=jd[i]*qpow(p[j],k)%mod; break; }
			jd[i*p[j]]=jd[i]*(qpow(p[j],k)-1+mod)%mod;
		}
		ans[i]=ans[i-1]*jd[i]%mod;
	}
}
int main()
{
	int t,n,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		sieve(n,k);
		printf("%lld\n",ans[n]);
	}
}