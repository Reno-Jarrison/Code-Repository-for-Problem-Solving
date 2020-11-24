#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
ll a[maxn];
int main()
{
	int n;
	while(scanf("%d",&n)&&n)
	{
		ll ans=0;
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		for(int i=1;i<n;i++)
			ans+=abs(a[i]),a[i+1]+=a[i];
		printf("%lld\n",ans);
	}
}