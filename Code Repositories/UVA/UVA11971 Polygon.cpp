#include<cstdio>
#define ll long long
using namespace std;
ll gcd(ll x,ll y)
{	return y?gcd(y,x%y):x; }
int main()
{
	int t,n,k,cases=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		ll denom=1LL<<k,numer=denom-k-1;
		ll d=gcd(numer,denom);
		if(!d) numer=0,denom=1;
		else numer/=d,denom/=d;
		printf("Case #%d: %lld/%lld\n",++cases,numer,denom);
	}
}