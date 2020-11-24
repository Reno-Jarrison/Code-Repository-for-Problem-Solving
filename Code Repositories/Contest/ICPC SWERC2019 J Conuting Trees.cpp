#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5;
const ll mod=1e9+7;
ll fac[2*maxn],cat[maxn],inv[maxn],invf[maxn];
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
	cat[0]=inv[1]=fac[0]=1;
	for(int i=1;i<=2*n;i++)
		fac[i]=fac[i-1]*i%mod;
	invf[n]=qpow(fac[n],mod-2);
	for(int i=n-1;~i;i--)
		invf[i]=invf[i+1]*(i+1)%mod;
	for(int i=2;i<=n+1;i++)
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=n;i++)
		cat[i]=inv[i+1]*fac[2*i]%mod*invf[i]%mod*invf[i]%mod;
}
int main()
{
	init(1e6);
	int n,x;
	ll ans=1;
	scanf("%d",&n);
	stack<int>stk;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		int cur=x,cnt=0;
		while(!stk.empty()&&x<stk.top())
		{
			if(stk.top()==cur) cnt++;
			else
			{
				ans=ans*cat[cnt]%mod;
				cur=stk.top(),cnt=1;
			}
			stk.pop();
		}
		ans=ans*cat[cnt]%mod;
		stk.push(x);
	}
	int cur=-1,cnt=0;
	while(!stk.empty())
	{
		if(stk.top()==cur) cnt++;
		else
		{
			ans=ans*cat[cnt]%mod;
			cur=stk.top(),cnt=1;
		}
		stk.pop();
	}
	ans=ans*cat[cnt]%mod;
	printf("%lld\n",ans);		
}