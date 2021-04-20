#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
ll x[maxn],k;
ll gcd(ll a,ll b)
{	return !b?a:gcd(b,a%b); }
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%lld",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%lld",&x[i]);
		ll d=abs(x[2]-x[1]);
		for(int i=3;i<=n;i++)
			d=gcd(d,abs(x[i]-x[1]));
		puts(abs(k-x[1])%d==0?"YES":"NO");
	}
}