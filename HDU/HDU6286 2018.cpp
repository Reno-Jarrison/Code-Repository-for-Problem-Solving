#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll solve(ll x,ll y)
{
	ll ans=0;
	ans+=(x/1009-x/2018)*(y/2-y/2018);
	ans+=(x/2-x/2018)*(y/1009-y/2018);
	ans+=x/2018*y+y/2018*x-(x/2018)*(y/2018);
	return ans;
}
int main()
{
	ll a,b,c,d;
	while(~scanf("%lld%lld%lld%lld",&a,&b,&c,&d))
		printf("%lld\n",solve(b,d)+solve(a-1,c-1)-solve(a-1,d)-solve(c-1,b));
}