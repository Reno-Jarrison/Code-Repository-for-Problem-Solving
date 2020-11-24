#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a,ll b)
{	return !b?a:gcd(b,a%b); }
ll lcm(ll a,ll b)
{	return a/gcd(a,b)*b; }
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		ll x,ans=1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",&x),ans=lcm(ans,x);
		printf("%lld\n",ans);
	}
}