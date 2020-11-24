#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=5e4+5;
int siz[maxn],son[maxn],rt1,rt2;
struct edge
{
	int to,nxt;
	edge(int to=0,int nxt=0):to(to),nxt(nxt){}
}e[maxn<<1];
int etot,head[maxn];
void link(int u,int v)
{	e[++etot]=edge(v,head[u]),head[u]=etot; }
void dfs(int u,int f,int tot)
{
	siz[u]=1,son[u]=0;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==f) continue;
		dfs(v,u,tot);
		siz[u]+=siz[v];
		son[u]=max(son[u],siz[v]);
	}
	son[u]=max(son[u],tot-siz[u]);
	if(son[u]<son[rt1]) rt1=u,rt2=-1;
	else if(son[u]==son[rt1]) rt2=u;
}
int main()
{
	int n,u,v;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
		scanf("%d%d",&u,&v),link(u,v),link(v,u);
	rt1=0,rt2=-1,son[0]=n;
	dfs(1,0,n);
	if(rt2!=-1&&rt1>rt2) swap(rt1,rt2);
	if(rt2==-1) printf("%d",rt1);
	else printf("%d %d",rt1,rt2);
}