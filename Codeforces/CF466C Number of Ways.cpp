#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5;
int a[maxn],cnt[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	ll sum=0,cur=0,ans=0;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),sum+=a[i];
	if(sum%3==0)
	{
		sum/=3;
		for(int i=n;i>=3;i--)
			cur+=a[i],cnt[i]=cnt[i+1]+(cur==sum);
		cur=0;
		for(int i=1;i<=n-2;i++)
		{
			cur+=a[i];
			if(cur==sum) ans+=cnt[i+2];
		}
	}
	printf("%lld\n",ans);
}