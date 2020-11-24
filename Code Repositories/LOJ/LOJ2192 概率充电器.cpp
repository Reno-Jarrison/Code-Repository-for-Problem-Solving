#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
struct edge
{
	int to,w;
	edge(int to,int w):to(to),w(w){}
};
vector<edge>e[maxn];
void link(int u,int v,int w)
{	e[u].push_back(edge(v,w)),e[v].push_back(edge(u,w)); }
double q[maxn],dp1[maxn],dp2[maxn];
void dfs1(int u,int f)
{
	dp1[u]=1-q[u];
	for(int i=0;i<(int)e[u].size();i++)
	{
		int v=e[u][i].to; 
		double p=e[u][i].w/100.0;
		if(v==f) continue;
		dfs1(v,u);
		dp1[u]*=(1-p+p*dp1[v]);
	}
}
void dfs2(int u,int f)
{
	for(int i=0;i<(int)e[u].size();i++)
	{
		int v=e[u][i].to; 
		double p=e[u][i].w/100.0;
		if(v==f) continue;
		dp2[v]=dp1[v]*(1-p*(1-dp2[u]/(1-p+p*dp1[v])));
		dfs2(v,u);
	}
}
int main()
{
	int n,u,v,w;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
		scanf("%d%d%d",&u,&v,&w),link(u,v,w);
	for(int i=1;i<=n;i++)
		scanf("%d",&w),q[i]=w/100.0;
	dfs1(1,0),dp2[1]=dp1[1],dfs2(1,0);
	double ans=0;
	for(int i=1;i<=n;i++)
		ans+=1-dp2[i];
	printf("%.6lf\n",ans);
}