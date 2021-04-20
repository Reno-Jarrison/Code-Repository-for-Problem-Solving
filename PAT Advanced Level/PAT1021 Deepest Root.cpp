#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5,inf=0x3f3f3f3f;
vector<int>e[maxn];
set<int>ans;
int f[maxn],dp[maxn][2],g[maxn],mxv;
int find(int x)
{	return x==f[x]?x:f[x]=find(f[x]); }
void getmax(int dist,int id)
{
	if(dist<mxv) return;
	if(dist>mxv) 
		ans.clear(),mxv=dist;
	ans.insert(id); 
}
void dfs1(int u,int f)
{
	dp[u][0]=dp[u][1]=0;
	for(int v:e[u])
	{
		if(v==f) continue;
		dfs1(v,u);
		if(dp[v][0]+1>=dp[u][0])
			dp[u][1]=dp[u][0],dp[u][0]=dp[v][0]+1;
		else dp[u][1]=max(dp[u][1],dp[v][0]+1);
	}
	getmax(dp[u][0],u);
}
void dfs2(int u,int f,int w)
{
	g[u]=max(g[f],dp[u][0]+1==dp[f][0]?dp[f][1]:dp[f][0])+w;
	getmax(g[u],u);
	for(int v:e[u])
		if(v!=f) dfs2(v,u,1);
}
int main()
{
	int n,u,v,cnt;
	scanf("%d",&n),cnt=n;
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		int fu=find(u),fv=find(v);
		if(fu!=fv) cnt--,f[fu]=fv;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(cnt>1)
		printf("Error: %d components\n",cnt);
	else
	{
		dfs1(1,0),dfs2(1,0,0);
		for(int x:ans) 
			printf("%d\n",x);
	}
}