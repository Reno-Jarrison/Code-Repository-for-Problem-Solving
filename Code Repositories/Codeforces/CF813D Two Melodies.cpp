#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5,maxm=1e5+5;
int a[maxn],dp[maxn][maxn],mxv1[maxm],mxv2[7];
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<=n;i++)
	{
		memset(mxv1,0,sizeof(mxv1));
		memset(mxv2,0,sizeof(mxv2));
		for(int j=1;j<i;j++)
		{
			mxv1[a[j]]=max(mxv1[a[j]],dp[i][j]);
			mxv2[a[j]%7]=max(mxv2[a[j]%7],dp[i][j]);
		}
		for(int j=i+1;j<=n;j++)
		{
			dp[i][j]=max(mxv1[a[j]-1],mxv1[a[j]+1])+1;
			dp[i][j]=max(dp[i][j],max(dp[i][0],mxv2[a[j]%7])+1);
			mxv1[a[j]]=max(mxv1[a[j]],dp[i][j]);
			mxv2[a[j]%7]=max(mxv2[a[j]%7],dp[i][j]);
			dp[j][i]=dp[i][j];
			ans=max(ans,dp[i][j]);
		}
	}
	printf("%d\n",ans);
}