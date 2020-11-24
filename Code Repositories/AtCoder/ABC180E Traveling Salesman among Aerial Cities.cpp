#include<bits/stdc++.h>
using namespace std;
int dp[1<<16][16],x[20],y[20],z[20];
int dist(int u,int v)
{	return abs(x[u]-x[v])+abs(y[u]-y[v])+max(0,z[v]-z[u]); }
void update(int& cur,int val)
{	cur=min(cur,val); }
int main()
{
	int n;
	scanf("%d",&n);
	scanf("%d%d%d",&x[n],&y[n],&z[n]);
	memset(dp,0x3f,sizeof(dp));
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d%d",&x[i],&y[i],&z[i]);
		dp[1<<i][i]=dist(n,i);
	}
	for(int i=1;i<(1<<(n-1));i++)
	{
		int sta=i;
		for(int j=0;j<n-1;j++,sta>>=1) if(sta&1)
			for(int k=0;k<n-1;k++) if(!(i&(1<<k))) 
				update(dp[i|(1<<k)][k],dp[i][j]+dist(j,k));
	}
	int ans=1e8;
	for(int i=0;i<n-1;i++)
		ans=min(ans,dp[(1<<(n-1))-1][i]+dist(i,n));
	printf("%d\n",ans);
}