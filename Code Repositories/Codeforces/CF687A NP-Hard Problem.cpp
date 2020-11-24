#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
vector<int>e[maxn],vec[2];
void link(int u,int v)
{	e[u].push_back(v),e[v].push_back(u); }
int c[maxn];
bool dfs(int u,int tag)
{
	c[u]=tag;
	vec[tag].push_back(u);
	for(int v:e[u])
	{
		if(c[v]==!tag) continue;
		if(c[v]==tag||!dfs(v,!tag)) return false;
	}
	return true;
}
int main()
{
	int n,m,ok=1,u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&u,&v),link(u,v);
	memset(c,-1,sizeof(c));
	for(int i=1;i<=n;i++)
		if(c[i]==-1) ok&=dfs(i,0);
	if(!ok) puts("-1");
	else
	{
		printf("%d\n",(int)vec[0].size());
		for(int x:vec[0]) printf("%d ",x);
		printf("\n%d\n",(int)vec[1].size());
		for(int x:vec[1]) printf("%d ",x);
	}
}