#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=1e5+5;
int w[maxn],lg2[maxn]={-1},fat[maxn][20],dep[maxn],ans;
struct edge
{
	int to,nxt;
	edge(int to=0,int nxt=0):to(to),nxt(nxt){}
}e[maxn<<1];
int head[maxn<<1],cnt;
void init()
{	memset(head,-1,sizeof(head)),cnt=0; }
void link(int u,int v)
{	e[cnt]=edge(v,head[u]),head[u]=cnt++; }
void getlg2()
{	for(int i=1;i<=maxn-5;i++) lg2[i]=lg2[i>>1]+1; }
int getlca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y])
		x=fat[x][lg2[dep[x]-dep[y]]];
	if(x==y) return x;
	for(int i=lg2[dep[x]];i>=0;i--)
		if(fat[x][i]!=fat[y][i])
			x=fat[x][i],y=fat[y][i];
	return fat[x][0];
}
void dfs1(int u,int f)
{
	fat[u][0]=f,dep[u]=dep[f]+1;
	for(int i=1;(1<<i)<=dep[u];i++)
		fat[u][i]=fat[fat[u][i-1]][i-1];
	for(int i=head[u];~i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v!=f) dfs1(v,u);
	}
}
void dfs2(int u,int m)
{
	for(int i=head[u];~i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==fat[u][0]) continue;
		dfs2(v,m),w[u]+=w[v];
	}
	if(u==1) return;
	if(w[u]==0) ans+=m;
	else if(w[u]==1) ans+=1;
}
int main()
{
	int n,m,x,y;
	init(),getlg2();
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
		scanf("%d%d",&x,&y),link(x,y),link(y,x);
	dfs1(1,0);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		int lca=getlca(x,y);
		w[x]++,w[y]++,w[lca]-=2;
	}
	dfs2(1,m);
	printf("%d",ans);
}