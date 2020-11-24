#include<cstdio>
#include<vector>
using namespace std;
const int maxn=4e4+4;
int dp1[maxn][2],dp2[maxn],ans;
struct edge
{
	int to,w;
	edge(int to,int w):to(to),w(w){}
};
vector<edge>e[maxn];
void link(int u,int v,int w)
{	e[u].push_back(edge(v,w)),e[v].push_back(edge(u,w)); }
void dfs1(int u,int f)
{
	for(int i=0;i<e[u].size();i++)
	{
		int v=e[u][i].to,w=e[u][i].w;
		if(v==f) continue;
		dfs1(v,u);
		int val=dp1[v][0]+w;
		if(dp1[u][0]<val)
			dp1[u][1]=dp1[u][0],dp1[u][0]=val;
		else if(dp1[u][1]<val) dp1[u][1]=val;
	}
}
void dfs2(int u,int f)
{
	ans=max(ans,dp1[u][0]+dp2[u]);
	for(int i=0;i<e[u].size();i++)
	{
		int v=e[u][i].to,w=e[u][i].w;
		if(v==f) continue;
		if(dp1[u][0]==dp1[v][0]+w)
			dp2[v]=dp1[u][1]+w;
		else dp2[v]=dp1[u][0]+w;
		dfs2(v,u);
	}
}
int main()
{
	int n,m,u,v,w; char s[2];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d%s",&u,&v,&w,s),link(u,v,w);
	dfs1(1,0),dfs2(1,0);
	printf("%d\n",ans);
}