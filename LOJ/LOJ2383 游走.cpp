#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
int deg[maxn],g[maxn][maxn];
double mat[maxn][maxn],dp[maxn*maxn];
void gauss(int n)
{
	for(int i=1;i<=n;i++)
	{
		int pt=i;
		for(int j=i+1;j<=n;j++)
			if(fabs(mat[j][i])>fabs(mat[pt][i])) pt=j;
		if(i!=pt) swap(mat[i],mat[pt]);
		for(int j=i+1;j<=n;j++)
			for(int k=n+1;k>=i;k--)
				mat[j][k]-=mat[j][i]/mat[i][i]*mat[i][k];
	}
	for(int i=n;i;i--)
	{
		for(int j=i+1;j<=n;j++)
			mat[i][n+1]-=mat[i][j]*mat[j][n+1];
		mat[i][n+1]/=mat[i][i];
	}
}
int main()
{
	int n,m,u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		g[u][v]=g[v][u]=1,deg[u]++,deg[v]++;
	}
	for(int i=1;i<n;i++) 
	{
		mat[i][i]=1;
		for(int j=1;j<n;j++)
			if(g[i][j]) mat[i][j]=-1.0/deg[j];
	}
	mat[n][n]=mat[1][n+1]=1;
	gauss(n);
	int idx=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++) if(g[i][j]) 
			dp[++idx]=mat[i][n+1]/deg[i]+mat[j][n+1]/deg[j];
	sort(dp+1,dp+m+1);
	double ans=0;
	for(int i=1;i<=m;i++) ans+=dp[i]*(m-i+1);
	printf("%.3lf",ans);
}