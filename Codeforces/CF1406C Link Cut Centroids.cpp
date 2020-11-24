#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
vector<int>e[maxn];
int siz[maxn],son[maxn],ctd1,ctd2;
void link(int u,int v)
{	e[u].push_back(v),e[v].push_back(u); }

void dfs(int u,int f,int tot)
{
	siz[u]=1,son[u]=0;
	for(int v:e[u]) if(v!=f)
	{
		dfs(v,u,tot);
		siz[u]+=siz[v];
		son[u]=max(son[u],siz[v]);
	}
	son[u]=max(son[u],tot-siz[u]);
	if(son[u]<son[ctd1]) ctd1=u;
	else if(son[u]==son[ctd1]) ctd2=u;
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
		ctd1=ctd2=0,son[0]=n;
		dfs(1,0,n);
		if(son[ctd1]!=son[ctd2])
			printf("%d %d\n%d %d\n",1,e[1][0],1,e[1][0]);
		else for(int x:e[ctd1]) if(x!=ctd2)
		{	printf("%d %d\n%d %d\n",ctd1,x,ctd2,x); break; }
	}
}