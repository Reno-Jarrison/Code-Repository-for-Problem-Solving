#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int tag[maxn],siz[maxn],ans,k;
vector<int>e[maxn];
void link(int u,int v)
{	e[u].push_back(v),e[v].push_back(u); }
void dfs(int u,int f)
{
	siz[u]=tag[u];
	int cnt=0;
	for(int v:e[u]) if(v!=f)
	{
		dfs(v,u);
		siz[u]+=siz[v];
		if(siz[v]) cnt++;
	}
	if(siz[u]<k) cnt++;
	if(tag[u]||cnt>=2) ans++;
}
int main()
{
	int n,u,v,w,x;
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;i++)
		scanf("%d%d%d",&u,&v,&w),link(u,v);
	for(int i=1;i<=k;i++)
		scanf("%d",&x),tag[x]=1;
	dfs(1,0);
	printf("%d\n",ans);
}