#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t,n,m;
	ll k,a;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%lld",&n,&m,&k);
		ll ans=0,mnv=n;
		for(int i=1;i<=m;i++)
		{
			scanf("%lld",&a),ans+=2LL*abs(a-k);
			mnv=min(mnv,a);
		}
		if(mnv<k) ans-=2LL*abs(k-mnv);
		printf("%lld\n",ans+2LL*(k-1));
	}
}