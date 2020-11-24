#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int lg2[maxn]={-1},dep[maxn],fat[maxn][20];
int idx,id[maxn],dfn[maxn],stk[maxn];
int dp[maxn],siz[maxn],vis[maxn];
vector<int>e[maxn];
void link(int u,int v)
{	e[u].push_back(v),e[v].push_back(u); }
void getlg2(int n)
{	for(int i=1;i<=n;i++) lg2[i]=lg2[i>>1]+1; }
void dfs1(int u,int f)
{
	dep[u]=dep[f]+1,fat[u][0]=f,dfn[u]=++idx;
	for(int i=1;(1<<i)<=dep[u];i++)
		fat[u][i]=fat[fat[u][i-1]][i-1];
	for(int v:e[u]) if(v!=f) dfs1(v,u);
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
bool cmp(int a,int b)
{	return dfn[a]<dfn[b]; }
void build(int k,int rt)
{
	sort(id+1,id+k+1,cmp);
	int top=0;
	e[rt].clear(),stk[++top]=rt;
	for(int i=1;i<=k;i++)
	{
		if(id[i]==rt) continue;
		int lca=getlca(id[i],stk[top]);
		if(lca!=stk[top])
		{
			while(dfn[lca]<dfn[stk[top-1]])
				link(stk[top-1],stk[top]),top--;
			if(lca!=stk[top-1]) 
				e[lca].clear(),link(lca,stk[top]),stk[top]=lca;
			else link(lca,stk[top--]);
		}
		e[id[i]].clear(),stk[++top]=id[i];
	}
	while(top>1) link(stk[top-1],stk[top]),top--;
}
void dfs2(int u,int f)
{
	dp[u]=siz[u]=0;
	for(int v:e[u]) if(v!=f)
		dfs2(v,u),dp[u]+=dp[v],siz[u]+=siz[v];
	if(vis[u]) dp[u]+=siz[u],siz[u]=1;
	else if(siz[u]>1) dp[u]++,siz[u]=0;
}
int main()
{
	getlg2(1e5);
	int n,u,v,q,k;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
		scanf("%d%d",&u,&v),link(u,v);
	dfs1(1,0);
	vector<int>vec;
	scanf("%d",&q);
	while(q--)
	{
		for(int x:vec) vis[x]=0;
		vec.clear();
		scanf("%d",&k);
		for(int i=1;i<=k;i++)
			scanf("%d",&id[i]),vis[id[i]]=1,vec.push_back(id[i]);
		int ok=1;
		for(int i=1;i<=k&&ok;i++)
			if(vis[fat[id[i]][0]]) ok=0;
		if(!ok)
		{	puts("-1"); continue; }
		build(k,1),dfs2(1,0);
		printf("%d\n",dp[1]);
	}
}