#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5;
struct edge
{
	int to,w;
	edge(int to,int w):to(to),w(w){}
};
vector<edge>e[maxn];
int col[maxn],dis[maxn],vis[maxn];
void bfs(int s)
{
	dis[s]=0,vis[s]=1;
	queue<int>que;
	que.push(s);
	while(!que.empty())
	{
		int u=que.front(); que.pop();
		for(edge x:e[u])
		{
			int v=x.to,w=x.w;
			if(vis[v]) continue;
			if(col[v]==-1) col[v]=w^1;
			else if(col[v]==w)
				vis[v]=1,dis[v]=dis[u]+1,que.push(v);
		}
	}
}
int main()
{
	int n,m,u,v,w;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&u,&v,&w),e[v].push_back(edge(u,w));
	memset(col,-1,sizeof(col)),bfs(n);
	printf("%d\n",vis[1]?dis[1]:-1);
	for(int i=1;i<=n;i++)
		printf("%d",col[i]!=-1?col[i]:0);
}