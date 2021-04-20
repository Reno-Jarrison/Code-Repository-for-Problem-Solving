#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e6+5;
int tot,p[maxn],lpf[maxn],vis[maxn],mod,cnt[maxn],power[maxn];
void getprime(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!vis[i]) p[++tot]=i,lpf[i]=i;
		for(int j=1;i*p[j]<=n;j++)
		{
			vis[i*p[j]]=1;
			lpf[i*p[j]]=p[j];
			if(i%p[j]==0) break;
		}
	}
}
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
void calc(int n,int val)
{
	for(int i=n;i>1;i--)
	{
		cnt[i]++;
		if(!vis[i]) power[i]+=cnt[i]*val;
		else cnt[lpf[i]]+=cnt[i],cnt[i/lpf[i]]+=cnt[i];
		cnt[i]=0;
	}
}
int main()
{
	int n,tmp;
	scanf("%d%d",&n,&mod),tmp=n+1;
	getprime(2*n);
	calc(2*n,1),calc(n,-2);
	while(tmp>1)
		power[lpf[tmp]]--,tmp/=lpf[tmp];
	ll ans=1;
	for(int i=2;i<=2*n;i++)
		if(!vis[i]) ans=ans*qpow(i,power[i])%mod;
	printf("%lld\n",ans);
}