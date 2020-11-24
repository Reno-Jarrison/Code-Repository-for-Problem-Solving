#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
ll sum(ll l,ll r)
{	return (l+r)*(r-l+1)/2; }
int main()
{
	ll n,k,ans=0;
	scanf("%lld%lld",&n,&k);
	ans=n*k,n=min(n,k);
	for(ll l=1,r;l<=n;l=r+1)
	{
		r=min(k/(k/l),n);
		ans-=k/l*sum(l,r);
	}
	printf("%lld\n",ans);
}