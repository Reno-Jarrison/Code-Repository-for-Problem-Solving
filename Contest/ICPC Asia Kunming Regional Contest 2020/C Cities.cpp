#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+5;
int a[maxn],dp[maxn][maxn],pos[maxn],pre[maxn],suc[maxn];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,x,tot=0,las=-1;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&x);
			if(x!=las) a[++tot]=x;
			pos[i]=0,suc[i]=n+1,las=x;
		}
		for(int i=1;i<=tot;i++)
		{
			pre[i]=pos[a[i]];
			suc[pos[a[i]]]=i;
			pos[a[i]]=i;
		}
		for(int len=2;len<=tot;len++)
			for(int l=1,r=l+len-1;r<=tot;l++,r++)
			{
				dp[l][r]=min(dp[l][r-1],dp[l+1][r])+(a[l]!=a[r]);
				for(int i=suc[l];i<=r;i=suc[i])
					dp[l][r]=min(dp[l][r],dp[l][i-1]+dp[i][r]);
				for(int i=pre[r];i>=l;i=pre[i])
					dp[l][r]=min(dp[l][r],dp[l][i]+dp[i+1][r]);
			}
		printf("%d\n",dp[1][tot]);
	}
}