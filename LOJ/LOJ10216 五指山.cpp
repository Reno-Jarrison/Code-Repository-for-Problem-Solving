#include<bits/stdc++.h>
#define ll long long
using namespace std;
void exgcd(ll a,ll b,ll& d,ll& x,ll& y)
{
	if(!b) d=a,x=1,y=0;
	else exgcd(b,a%b,d,y,x),y-=a/b*x;
}
int main()
{
	ll t,n,d,x,y,c,d0,x0,y0,mod;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld%lld%lld%lld",&n,&d,&x,&y);
		c=y-x;
		exgcd(d,n,d0,x0,y0);
		mod=abs(n/d0);
		if(c%d0) { printf("Impossible\n"); continue; }
		else printf("%lld\n",(x0*c/d0%mod+mod)%mod);
	}
}