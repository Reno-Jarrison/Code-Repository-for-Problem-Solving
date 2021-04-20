#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
int tot,vis[maxn],p[maxn];
void init(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!vis[i]) p[++tot]=i;
		for(int j=1;i*p[j]<=n;j++)
		{
			vis[i*p[j]]=1;
			if(i%p[j]==0) break;
		}
	}
}
ll getphi(ll x)
{
	ll ans=1;
	for(int i=1;1LL*p[i]*p[i]<=x;i++)
		if(x%p[i]==0)
		{
			x/=p[i];
			ll tmp=1;
			while(x%p[i]==0) 
				x/=p[i],tmp*=p[i];
			ans*=tmp*(p[i]-1);
		}
	if(x>1) ans*=x-1;
	return ans;
}
ll gcd(ll a,ll b)
{	return !b?a:gcd(b,a%b); }
int main()
{
	init(2e5);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll a,m;
		scanf("%lld%lld",&a,&m);
		printf("%lld\n",getphi(m/gcd(a,m)));
	}
}