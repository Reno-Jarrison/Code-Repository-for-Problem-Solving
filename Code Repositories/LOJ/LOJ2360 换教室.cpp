#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+5;
int c[maxn],d[maxn],dist[305][305];
double k[maxn],dp[maxn][maxn][2];
void floyd(int n)
{
	for(int k=1;k<=n;k++)
	{
		dist[k][k]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]); 
	}
}
int main()
{
	int n,m,v,e;
	scanf("%d%d%d%d",&n,&m,&v,&e);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=1;i<=n;i++) scanf("%d",&d[i]);
	for(int i=1;i<=n;i++) scanf("%lf",&k[i]);
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=e;i++)
	{
		int a,b,w;
		scanf("%d%d%d",&a,&b,&w);
		dist[a][b]=dist[b][a]=min(dist[a][b],w);
	}
	floyd(v);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++) 
			dp[i][j][0]=dp[i][j][1]=1e6;
	dp[1][0][0]=dp[1][1][1]=0;
	for(int i=2;i<=n;i++)
		for(int j=0;j<=min(i,m);j++)
		{
			int c0=c[i-1],c1=c[i],d0=d[i-1],d1=d[i];
			int w1=dist[c0][c1],w2=dist[d0][d1],w3=dist[c0][d1],w4=dist[d0][c1];
			double p0=k[i-1],p1=k[i],q0=1.0-p0,q1=1.0-p1;
			dp[i][j][0]=dp[i-1][j][0]+w1;
			if(j==0) continue;
			dp[i][j][0]=min(dp[i][j][0],dp[i-1][j][1]+p0*w4+q0*w1);
			dp[i][j][1]=min(dp[i][j][1],dp[i-1][j-1][0]+p1*w3+q1*w1);
			dp[i][j][1]=min(dp[i][j][1],dp[i-1][j-1][1]+p0*p1*w2+q0*q1*w1+q0*p1*w3+p0*q1*w4);
		}
	double ans=1e6;
	for(int i=0;i<=m;i++)
		ans=min(ans,min(dp[n][i][1],dp[n][i][0]));
	printf("%.2lf",ans);
}