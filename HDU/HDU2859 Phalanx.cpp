#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
char s[maxn][maxn];
int dp1[maxn][maxn],dp2[maxn][maxn];
int main()
{
	int n;
	while(scanf("%d",&n)&&n)
	{
		for(int i=1;i<=n;i++)
			scanf("%s",s[i]+1);
		for(int i=1;i<=n;i++)
			for(int j=n;j;j--)
				for(int k=0;i-k<=n&&j+k<=n;k++)
				{
					if(s[i-k][j]==s[i][j+k]) dp1[i][j]=k+1;
					else break;
				}
		dp2[0][n+1]=0;
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=n;j;j--)
			{
				dp2[i][j]=min(dp1[i][j],dp2[i-1][j+1]+1);
				ans=max(ans,dp2[i][j]);
			}
		printf("%d\n",ans);
	}
}