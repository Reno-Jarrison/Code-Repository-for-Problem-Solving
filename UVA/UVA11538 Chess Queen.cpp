#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5;
ll sum[maxn];
int main()
{
	for(int i=2;i<maxn;i++)
		sum[i]=sum[i-1]+1LL*i*(i-1)*2;
	ll n,m;
	while(scanf("%lld%lld",&n,&m)&&n)
	{
		if(n>m) swap(n,m);
		ll ans=n*m*(m+n-2)+sum[n-1]*2;
		ans+=n*(n-1)*(m-n+1)*2;
		printf("%lld\n",ans);
	}
}