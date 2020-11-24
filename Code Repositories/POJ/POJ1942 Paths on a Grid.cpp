#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll C(ll n,ll m)
{
	long double ans=1;
	for(ll i=n,j=m;j;i--,j--)
		ans*=1.0*i/j;
	return (ll)(ans+0.5);
}
int main()
{
	ll n,m;
	while(scanf("%lld%lld",&n,&m)&&(n||m))
		printf("%lld\n",C(n+m,min(n,m)));
}