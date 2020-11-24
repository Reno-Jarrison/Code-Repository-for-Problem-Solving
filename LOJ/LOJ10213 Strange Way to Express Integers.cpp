#include<bits/stdc++.h>
#define ll long long
#define maxn 100005
ll a[maxn],m[maxn]; 
using namespace std;
ll qmul(ll a,ll b,ll c)
{
	ll hbit=a*(b>>25)%c*(1<<25)%c;
	ll lbit=a*(b&(1<<25)-1)%c;
	return (hbit+lbit)%c;
}
void exgcd(ll a,ll b,ll& d,ll& x,ll& y)
{
	if(!b) d=a,x=1,y=0;
	else exgcd(b,a%b,d,y,x),y-=a/b*x;
}
ll excrt(int n)
{
	ll lcm=1,ans=0,c,d,x,y,mod;
	for(int i=1;i<=n;i++)
	{
		c=(a[i]-ans%m[i]+m[i])%m[i];
		exgcd(lcm,m[i],d,x,y);
		if(c%d) return -1;
		x=qmul(x,c/d,mod=m[i]/d);
		ans+=lcm*x,lcm*=mod;
		ans=(ans+lcm)%lcm;
	}
	return ans;
}
int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;i++)
			scanf("%lld%lld",&m[i],&a[i]);
		printf("%lld\n",excrt(n));
	}
}