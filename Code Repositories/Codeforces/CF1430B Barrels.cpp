#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
ll a[maxn];
int main()
{
	int t,n,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		sort(a+1,a+n+1,greater<ll>());
		ll ans=0;
		for(int i=1;i<=k+1;i++)
			ans+=a[i];
		printf("%lld\n",n==1?0:ans);
	}
}