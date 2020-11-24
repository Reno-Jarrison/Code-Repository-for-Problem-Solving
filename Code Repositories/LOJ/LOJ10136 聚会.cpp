#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
vector<int>e[maxn];
int dep[maxn],fat[maxn][20],lg2[maxn]={-1};
void getlg2(int n)
{	for(int i=1;i<=n;i++) lg2[i]=lg2[i>>1]+1; }
void link(int u,int v)
{	e[u].push_back(v),e[v].push_back(u); }
void dfs(int u,int f)
{
	dep[u]=dep[f]+1,fat[u][0]=f;
	for(int i=1;(1<<i)<=dep[u];i++)
		fat[u][i]=fat[fat[u][i-1]][i-1];
	for(int v:e[u]) 
		if(v!=f) dfs(v,u);
}
int getlca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y])
		x=fat[x][lg2[dep[x]-dep[y]]];
	if(x==y) return x;
	for(int i=lg2[dep[x]];~i;i--)
		if(fat[x][i]!=fat[y][i])
			x=fat[x][i],y=fat[y][i];
	return fat[x][0];
}
int getdis(int x,int y,int lca)
{	return dep[x]+dep[y]-2*dep[lca]; }
int main()
{
	getlg2(maxn-5);
	int n,m,u,v,x,y,z;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
		scanf("%d%d",&u,&v),link(u,v);
	dfs(1,0);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&y,&z);
		int lca1=getlca(x,y),lca2=getlca(y,z),lca3=getlca(x,z);
		int cost=getdis(x,y,lca1)+getdis(y,z,lca2)+getdis(x,z,lca3);
		int dst=dep[lca1]>dep[lca2]?lca1:lca2;
		dst=dep[lca3]>dep[dst]?lca3:dst;
		printf("%d %d\n",dst,cost/2);
	}
}