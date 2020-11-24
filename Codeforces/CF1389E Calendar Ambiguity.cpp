#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll sum(ll x)
{	return x*(x+1)/2; }
ll gcd(ll a,ll b)
{	return !b?a:gcd(b,a%b); }
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll m,d,w,lim,ans;
		scanf("%lld%lld%lld",&m,&d,&w);
		w/=gcd(d-1,w),lim=min(d,m)-1;
		ans=w*sum(lim/w-1)+lim/w*(lim%w+1);
		printf("%lld\n",ans);
	}
}