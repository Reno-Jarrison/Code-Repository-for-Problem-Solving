#include<bits/stdc++.h>
#define ll long long
using namespace std;
void exgcd(ll a,ll b,ll& d,ll& x,ll& y)
{
	if(b) exgcd(b,a%b,d,y,x),y-=a/b*x;
	else d=a,x=1,y=0;
}
int main()
{
	ll x,y,m,n,l;
	ll a,b,c,d,x0,y0,mod;
	cin>>x>>y>>m>>n>>l;
	a=m-n,b=-l,c=y-x;
	exgcd(a,b,d,x0,y0);
	mod=abs(b/d);
	if(c%d) printf("Impossible");
	else x0*=c/d,printf("%lld",(x0%mod+mod)%mod);
}