#include<cstdio>
#include<cmath>
#define ll long long
using namespace std;
void exgcd(ll a,ll b,ll& d,ll& x,ll& y)
{
	if(!b) d=a,x=1,y=0;
	else exgcd(b,a%b,d,y,x),y-=a/b*x;
}
int main()
{
	ll a,b,c,k,m;
	while(scanf("%lld%lld%lld%lld",&a,&b,&c,&k)!=EOF)
	{
		if(!a&&!b&&!c&&!k) break;
		m=1LL<<k;
		ll d,x,y,mod;
		exgcd(c,m,d,x,y);
		if((b-a)%d) printf("FOREVER\n");
		else
		{
			mod=m/d,mod<0?mod=-mod:false;
			printf("%lld\n",(x*(b-a)/d%mod+mod)%mod);
		}
	}
}
