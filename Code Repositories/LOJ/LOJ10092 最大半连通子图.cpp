#include<bits/stdc++.h>
#define maxn 100005
#define mod 1926817
using namespace std;
struct edge { int u,v; };
vector<int>e[maxn],newe[maxn];
vector<edge>h[mod];
stack<int>s;
int dep,sum,dfn[maxn],low[maxn],color[maxn];
int cnt[maxn],ind[maxn],dp[maxn],num[maxn];
bool vis[maxn];
inline bool check(int u,int v)
{
	int hval=(1LL*u*v%mod+v)%mod,len;
	len=h[hval].size();
	for(int i=0;i<len;i++)
		if(h[hval][i].u==u&&h[hval][i].v==v) return false;
	h[hval].push_back({u,v});
	return true;
}
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
	int n,m,x,u,v;
	scanf("%d%d%d",&n,&m,&x);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&u,&v),e[u].push_back(v);
	for(int i=1;i<=n;i++) tarjan(i);
	for(int i=1;i<=n;i++)
	{
		cnt[color[i]]++;
		vector<int>::iterator it;
		for(it=e[i].begin();it!=e[i].end();++it)
		{
			u=color[i],v=color[*it];
			if(u!=v&&check(u,v))
				newe[u].push_back(v),ind[v]++;
		}	
	}
	queue<int>q;
	for(int i=1;i<=sum;i++)
		if(!ind[i]) q.push(i),num[i]=cnt[i],dp[i]=1;
	while(!q.empty())
	{
		u=q.front(),q.pop();
		vector<int>::iterator it;
		for(it=newe[u].begin();it!=newe[u].end();++it)
		{
			v=*it,ind[v]--;
			if(!ind[v]) q.push(v);
			if(num[v]<num[u]+cnt[v])
				num[v]=num[u]+cnt[v],dp[v]=dp[u];
			else if(num[v]==num[u]+cnt[v])
				dp[v]=(dp[v]+dp[u])%x;
		}
	}
	int k=0,c=0;
	for(int i=1;i<=sum;i++)
		if(num[i]>k) k=num[i],c=dp[i];
		else if(num[i]==k) c=(c+dp[i])%x;
	printf("%d\n%d",k,c);
}