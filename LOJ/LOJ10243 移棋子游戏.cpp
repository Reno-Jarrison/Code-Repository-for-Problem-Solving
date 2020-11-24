#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=2e3+5;
vector<int>e[maxn];
int sg[maxn],ind[maxn];
bool vis[maxn],mex[maxn][maxn];
#include<iostream>
void dfs(int u,int n)
{
	if(vis[u]) return;
	vis[u]=true;
	for(int i=0;i<(int)e[u].size();i++)
		dfs(e[u][i],n),mex[u][sg[e[u][i]]]=true;
	for(int i=0;i<=n;i++)
		if(!mex[u][i]) { sg[u]=i; return; }
}
int main()
{
	int n,m,k,u,v,x,ans=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&u,&v),e[u].push_back(v),ind[v]++;
	for(int i=1;i<=n;i++)
		if(!ind[i]) dfs(i,n);
	for(int i=1;i<=k;i++)
		scanf("%d",&x),ans^=sg[x];
	printf(ans?"win":"lose");
}