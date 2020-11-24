#include<bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;
const int maxn=55;
ld mat[maxn][maxn];
int vis[maxn][maxn];
void update(int u,int v,ld x)
{	mat[u][u]+=x,mat[v][v]+=x,mat[u][v]-=x,mat[v][u]-=x; }
ll matrixtree(int n)
{
	for(int i=1;i<=n;i++)
	{
		int pt=i;
		for(int j=i+1;j<=n;j++)
			if(fabs(mat[j][i])>fabs(mat[pt][i])) pt=j;
		if(fabs(mat[pt][i])<1e-8) return 0;
		if(pt!=i) swap(mat[pt],mat[i]);
		for(int j=i+1;j<=n;j++)
		{
			ld p=mat[j][i]/mat[i][i];
			for(int k=i;k<=n;k++)
				mat[j][k]-=mat[i][k]*p;
		}
	}
	ld ans=1;
	for(int i=1;i<=n;i++) ans*=mat[i][i];
	return (ll)(ans+0.5);
}
int main()
{
	int n,m,k,u,v;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		memset(mat,0,sizeof(mat));
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=m;i++)
			scanf("%d%d",&u,&v),vis[u][v]=vis[v][u]=1;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				if(!vis[i][j]) update(i,j,1);
		printf("%lld\n",matrixtree(n-1));
	}
}