#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5;
char s1[maxn],s2[maxn];
int dp[maxn][maxn];
int main()
{
	int n,m,ans=0;
	scanf("%d%d%s%s",&n,&m,s1+1,s2+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			dp[i][j]=max(max(dp[i-1][j]-1,dp[i][j-1]-1),0);
			if(s1[i]==s2[j])
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]+2);
			ans=max(ans,dp[i][j]);
		}
	printf("%d\n",ans);
}