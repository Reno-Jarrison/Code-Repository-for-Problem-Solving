#include<bits/stdc++.h>
using namespace std;
const int maxn=105,inf=0x3f3f3f3f;
struct edge
{
	int to,w;
	edge(int to,int w):to(to),w(w){}
};
vector<edge>e[maxn];
void link(int u,int v,int w)
{	e[u].emplace_back(v,w); }
int sta[maxn][15],dis[maxn][15],sum[maxn],fst[maxn],sec[maxn],flag[maxn];
int dist[maxn][1<<10],dp[15][1<<10];
void dfs1(int u,int f,int id)
{
	sum[u]=fst[u]=sec[u]=flag[u]=0;
	if(sta[u][id]) flag[u]=1;
	for(auto x:e[u]) if(x.to!=f)
	{
		int v=x.to,w=x.w;
		dfs1(v,u,id);
		if(!flag[v]) continue;
		sum[u]+=sum[v]+w,flag[u]=1;
		if(fst[v]+w>fst[u])
			sec[u]=fst[u],fst[u]=fst[v]+w;
		else if(fst[v]+w>sec[u])
			sec[u]=fst[v]+w;
	}
}
void dfs2(int u,int f,int id,int fdis,int fmxd,int tag)
{
	if(sta[u][id]) tag=1;
	dis[u][id]=(sum[u]+fdis)*2-max(fmxd,fst[u]);
	for(auto x:e[u]) if(x.to!=f)
	{
		int v=x.to,w=x.w;
		if(!flag[v])
			dfs2(v,u,id,tag||sum[u]?fdis+sum[u]+w:0,tag||sum[u]?w+max(fmxd,fst[u]):0,tag||sum[u]);
		else if(fst[v]+w==fst[u])
		{
			int ntag=tag||sec[u];
			dfs2(v,u,id,ntag?fdis+sum[u]-sum[v]:0,ntag?w+max(fmxd,sec[u]):0,ntag);
		}
		else
			dfs2(v,u,id,fdis+sum[u]-sum[v],w+max(fmxd,fst[u]),1);
	}
}
int main()
{
	int n,m,k,u,v,w;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=0;j<k;j++)
			scanf("%d",&sta[i][j]);
	for(int i=1;i<n;i++)
		scanf("%d%d%d",&u,&v,&w),link(u,v,w),link(v,u,w);
	for(int i=0;i<k;i++)
		dfs1(1,0,i),dfs2(1,0,i,0,0,0);
	for(int i=1;i<=n;i++)
		for(int j=1;j<(1<<k);j++)
			for(int l=0;l<k;l++) if(j&(1<<l))
				dist[i][j]=max(dist[i][j],dis[i][l]);
	memset(dp,inf,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int l=1;l<(1<<k);l++)
				for(int s=l;s;s=(s-1)&l)
					if(dp[j-1][s^l]!=inf)
						dp[j][l]=min(dp[j][l],max(dp[j-1][s^l],dist[i][s]));
	int ans=inf;
	for(int i=1;i<=m;i++)
		ans=min(ans,dp[i][(1<<k)-1]);
	printf("%d\n",ans);
}