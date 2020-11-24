#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=3e3+5;
int a[maxn],pre[maxn][maxn];
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				pre[i][j]=pre[i-1][j];
			pre[i][a[i]]++;
		}
		ll ans=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans+=1LL*pre[i-1][a[j]]*(pre[n][a[i]]-pre[j][a[i]]);
		printf("%lld\n",ans);
	}
} 