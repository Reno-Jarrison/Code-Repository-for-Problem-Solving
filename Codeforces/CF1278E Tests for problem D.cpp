#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
vector<int>e[maxn];
void link(int u,int v)
{	e[u].push_back(v),e[v].push_back(u); }
int idx=0,l[maxn],r[maxn];
void dfs(int u,int f)
{
	int siz=e[u].size();
	for(int i=0;i<siz;i++)
		if(e[u][i]!=f)
			l[e[u][i]]=++idx;
	r[u]=++idx;
	for(int i=siz-1;~i;i--)
		if(e[u][i]!=f)
			dfs(e[u][i],u);
}
int main()
{
	int n,u,v;
	scanf("%d",&n);
	for(int i=1;i<n;i++)
		scanf("%d%d",&u,&v),link(u,v);
	l[1]=++idx,dfs(1,0);
	for(int i=1;i<=n;i++)
		printf("%d %d\n",l[i],r[i]);
}