#include<bits/stdc++.h>
#define maxn 10005
using namespace std;
int dep,sum,dfn[maxn],low[maxn],color[maxn],cnt[maxn],out[maxn];
bool vis[maxn];
stack<int>s;
vector<int>e[maxn];
void tarjan(int u)
{
	if(dfn[u]) return;
	dfn[u]=low[u]=++dep,vis[u]=true,s.push(u);
	vector<int>::iterator it;
	for(it=e[u].begin();it!=e[u].end();++it)
	{
		int v=*it;
		if(!dfn[v]) tarjan(v),low[u]=min(low[u],low[v]);
		else if(vis[v]) low[u]=min(low[u],low[v]);
	}
	if(dfn[u]==low[u])
	{
		color[u]=++sum,vis[u]=false;
		while(s.top()!=u) 
			color[s.top()]=sum,vis[s.top()]=false,s.pop();
		s.pop();
	}
}
int main()
{
	int n,m,a,b,ans=0,num=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&a,&b),e[a].push_back(b);
	for(int i=1;i<=n;i++) tarjan(i);
	vector<int>::iterator it;
	for(int i=1;i<=n;i++)
	{
		cnt[color[i]]++;
		for(int x:e[i])
			if(color[i]!=color[x])
				out[color[i]]++;
	}
	for(int i=1;i<=sum;i++)
		if(!out[i]) ans=cnt[i],num++;
	if(num>1) ans=0;
	printf("%d",ans);
}