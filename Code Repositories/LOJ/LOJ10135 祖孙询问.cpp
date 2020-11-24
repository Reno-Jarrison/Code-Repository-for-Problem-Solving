#include<bits/stdc++.h>
using namespace std;
const int maxn=4e4+5;
vector<int>e[maxn];
int lg2[maxn]={-1},dep[maxn],fat[maxn][20];
void link(int u,int v)
{	e[u].push_back(v),e[v].push_back(u); }
void getlg2(int n)
{	for(int i=1;i<=n;i++) lg2[i]=lg2[i>>1]+1; }
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
int main()
{
	getlg2(40000);
	int n,m,u,v,rt;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&u,&v);
		if(v==-1) rt=u;
		else link(u,v);
	}
	dfs(rt,0);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		int lca=getlca(u,v);
		if(lca==u) puts("1");
		else if(lca==v) puts("2");
		else puts("0");
	}
}