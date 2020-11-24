#include<bits/stdc++.h>
using namespace std;
const int maxn=25;
int dp[maxn][maxn][maxn][maxn],s[maxn][maxn];
int sum(int xl,int yl,int xr,int yr)
{	return s[xr][yr]+s[xl-1][yl-1]-s[xl-1][yr]-s[xr][yl-1]; }
int main()
{
	int n,m,k,ks=0,x,y;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		memset(s,0,sizeof(s));
		for(int i=1;i<=k;i++)
			scanf("%d%d",&x,&y),s[x][y]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		memset(dp,0x3f,sizeof(dp));
		for(int i=1;i<=n;i++)
			for(int xl=1,xr=xl+i-1;xr<=n;xl++,xr++)
				for(int j=1;j<=m;j++)
					for(int yl=1,yr=yl+j-1;yr<=m;yl++,yr++)
					{
						int tot=sum(xl,yl,xr,yr),&val=dp[xl][yl][xr][yr];
						if(tot<=1) val=0;
						for(int xk=xl;xk<xr;xk++)
							if(sum(xl,yl,xk,yr)&&sum(xk+1,yl,xr,yr))
								val=min(val,dp[xl][yl][xk][yr]+dp[xk+1][yl][xr][yr]+yr-yl+1);
						for(int yk=yl;yk<yr;yk++)
						{
							if(sum(xl,yl,xr,yk)&&sum(xl,yk+1,xr,yr))
								val=min(val,dp[xl][yl][xr][yk]+dp[xl][yk+1][xr][yr]+xr-xl+1);
						}
					}
		printf("Case %d: %d\n",++ks,dp[1][1][n][m]);
	}
}