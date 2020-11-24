#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll inf=1e18;
const int maxn=1e5+5;
ll a[maxn];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ll ans,mxv=-inf;
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]),mxv=max(mxv,a[i]);
		sort(a+1,a+n+1,[](ll x,ll y){ return abs(x)>abs(y); });
		if(mxv<0) ans=a[n]*a[n-1]*a[n-2]*a[n-3]*a[n-4];
		else
		{
			ans=a[1]*a[2]*a[3]*a[4]*a[5];
			for(int i=6;i<=n;i++)
				for(int j=1;j<=5;j++)
				{
					ll cur=a[i];
					for(int k=1;k<=5;k++)
						if(j!=k) cur*=a[k];
					ans=max(ans,cur);
				}
		}
		printf("%lld\n",ans);
	}
}