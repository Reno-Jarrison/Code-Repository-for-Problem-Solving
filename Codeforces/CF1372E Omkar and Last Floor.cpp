#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int itvl[maxn][maxn],itvr[maxn][maxn],dp[maxn][maxn];
int main()
{
	int n,m,x,lx,rx;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		for(int j=1;j<=x;j++)
		{
			scanf("%d%d",&lx,&rx);
			for(int k=lx;k<=rx;k++)
				itvl[i][k]=lx,itvr[i][k]=rx;
		}
	}
	for(int i=1;i<=m;i++)
		for(int l=1,r=l+i-1;r<=m;l++,r++)
			for(int j=l;j<=r;j++)
			{
				int cnt=0;
				for(int k=1;k<=n;k++)
					if(itvl[k][j]>=l&&itvr[k][j]<=r) cnt++;
				dp[l][r]=max(dp[l][r],dp[l][j-1]+dp[j+1][r]+cnt*cnt);
			}
	printf("%d\n",dp[1][m]);
}