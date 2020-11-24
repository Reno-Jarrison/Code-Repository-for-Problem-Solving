#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
ll a[maxn];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		ll sum=0,ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>0) sum+=a[i];
			else
			{
				ll cost=min(-a[i],sum);
				a[i]+=cost,sum-=cost,ans-=a[i];
			}
		}
		printf("%lld\n",ans);
	}
}