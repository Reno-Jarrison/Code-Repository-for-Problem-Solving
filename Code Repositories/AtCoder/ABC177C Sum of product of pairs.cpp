#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
int main()
{
	int n;
	scanf("%d",&n);
	ll ans=0,pre=0,x;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		ans=(ans+x*pre)%mod;
		pre=(pre+x)%mod;
	}
	printf("%lld\n",ans);
}	