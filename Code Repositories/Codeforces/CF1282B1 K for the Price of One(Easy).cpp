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
		ll p,sum1=0,sum2=0,ans1=0,ans2=0;
		scanf("%d%lld%d",&n,&p,&k);
		for(int i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		sort(a+1,a+n+1);
		for(int i=2;i<=n;i+=2)
		{
			if(sum1+a[i]>p)
			{
				if(sum1+a[i-1]<=p) ans1++;
				break;
			}
			ans1+=2,sum1+=a[i];
		}
		if((n&1)&&sum1+a[n]<=p) ans1++;
		if(n&&a[1]<=p) sum2=a[1],ans2++;
		for(int i=3;i<=n;i+=2)
		{
			if(sum2+a[i]>p)
			{
				if(sum2+a[i-1]<=p) ans2++;
				break;
			}
			ans2+=2,sum2+=a[i];
		}
		if(!(n&1)&&sum2+a[n]<=p) ans2++;
		printf("%lld\n",max(ans1,ans2));
	}
}