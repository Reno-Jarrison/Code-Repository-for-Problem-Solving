#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5;
int h[maxn],dp[maxn][maxn];
bool check(int l,int pt,int r)
{	return 1LL*(h[r]-h[pt])*(r-l)>1LL*(h[r]-h[l])*(r-pt); }
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&h[i]);
	for(int i=1;i<=n;i++)
	{
		dp[i][i]=1,ans^=1;
		int sum=1,pt=i-1;
		for(int j=i-1;j;j--)
		{
			if(check(j,pt,i))
				sum+=min(dp[j+1][pt],dp[j+1][pt-1]),pt=j;
			dp[j][i]=sum+min(dp[j][pt],dp[j][pt-1]);
			ans^=dp[j][i];
		}
	}
	printf("%d\n",ans);
}