#include<cstdio>
#include<vector>
using namespace std;
const int maxn=2e4+5;
int siz[maxn],son[maxn],rt;
vector<int>e[maxn];
void link(int u,int v)
{	e[u].push_back(v),e[v].push_back(u); }
void dfs(int u,int f,int tot)
{
	siz[u]=1,son[u]=0;
	for(int i=0;i<(int)e[u].size();i++)
	{
		int v=e[u][i];
		if(v==f) continue;
		dfs(v,u,tot);
		siz[u]+=siz[v];
		son[u]=max(son[u],siz[v]);
	}
	son[u]=max(son[u],tot-siz[u]);
	if(son[u]<son[rt]) rt=u;
	else if(son[u]==son[rt]) rt=min(rt,u);
}
int main()
{
	int t,n,u,v;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++)
			scanf("%d%d",&u,&v),link(u,v);
		rt=0,son[0]=n+1,dfs(1,0,n);
		printf("%d %d\n",rt,son[rt]);
	}
}