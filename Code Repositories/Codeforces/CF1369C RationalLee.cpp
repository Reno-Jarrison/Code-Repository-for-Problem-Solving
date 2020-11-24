#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
int a[maxn],w[maxn];
int main()
{
	int t,n,k;
	scanf("%d",&t);
	while(t--)
	{
		ll ans=0;
		scanf("%d%d",&n,&k);
		int lpt=1,rpt=n,cnt=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=k;i++)
			scanf("%d",&w[i]),cnt+=(w[i]==1);
		sort(a+1,a+n+1);
		sort(w+1,w+k+1);
		for(int i=1;i<=cnt;i++)
			ans+=2LL*a[rpt--];
		for(int i=k;i>cnt;i--)
			ans+=a[rpt--]+a[lpt],lpt+=w[i]-1;
		printf("%lld\n",ans);
	}
}