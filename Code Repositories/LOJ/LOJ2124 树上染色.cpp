#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e3+5;
struct edge
{
	int to,nxt; ll w;
	edge(int to=0,int nxt=0,ll w=0):to(to),nxt(nxt),w(w){}
}e[maxn<<1];
int head[maxn],cnt;
void init()
{	memset(head,-1,sizeof(head)),cnt=0; }
void link(int u,int v,ll w)
{	e[cnt]=edge(v,head[u],w),head[u]=cnt++; }
ll dp[maxn][maxn],w;
int siz[maxn],n,m;
void dfs(int u,int f)
{
	memset(dp[u],-0x3f,sizeof(dp[u]));
	siz[u]=1,dp[u][0]=dp[u][1]=0;
	for(int i=head[u];~i;i=e[i].nxt)
	{
		int v=e[i].to; ll w=e[i].w;
		if(v==f) continue;
		dfs(v,u);
		for(int j=min(m,siz[u]);~j;j--)
			for(int k=min(m-j,siz[v]);~k;k--)
			{
				ll val=w*(k*(m-k)+(siz[v]-k)*(n-m-siz[v]+k));
				dp[u][j+k]=max(dp[u][j+k],dp[u][j]+dp[v][k]+val);
			}
		siz[u]+=siz[v];
	}
}
int main()
{
	init();
	int u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
		scanf("%d%d%lld",&u,&v,&w),link(u,v,w),link(v,u,w);
	dfs(1,0);
	printf("%lld",dp[1][m]);
}