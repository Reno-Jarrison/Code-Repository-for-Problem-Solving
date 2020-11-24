#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn=50,inf=0x3f3f3f3f;
struct edge
{
	int u,v,w;
	edge(int u,int v,int w):u(u),v(v),w(w){}
};
vector<edge>e;
vector<int>g[maxn];
int ecnt,dis[maxn],cur[maxn],eid[maxn][maxn];
bool vis[maxn];
void link(int u,int v,int w)
{
	e.push_back(edge(u,v,w));
	e.push_back(edge(v,u,0));
	g[u].push_back(ecnt++);
	g[v].push_back(ecnt++);
}
void init(int n)
{
	ecnt=0,e.clear();
	for(int i=0;i<=n+1;i++)
		g[i].clear();
}
bool bfs(int s,int t)
{
	memset(dis,inf,sizeof(dis));
	memset(vis,0,sizeof(vis));
	queue<int>q;
	q.push(s),vis[s]=true,dis[s]=0;
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=0;i<(int)g[u].size();i++)
		{
			int id=g[u][i],v=e[id].v;
			if(!vis[v]&&e[id].w)
				q.push(v),vis[v]=true,dis[v]=dis[u]+1;
		}
	}
	return vis[t];
}
int dfs(int u,int t,int flow)
{
	if(u==t||!flow) return flow;
	int ans=0,tmp;
	for(int& i=cur[u];i<(int)g[u].size();i++)
	{
		int id=g[u][i],v=e[id].v,w=e[id].w;
		if(dis[v]==dis[u]+1&&(tmp=dfs(v,t,min(flow,w))))
		{
			e[id].w-=tmp,e[id^1].w+=tmp;
			flow-=tmp,ans+=tmp;
			if(!flow) break;
		}
	}
	return ans;
}
int dinic(int s,int t)
{
	int ans=0;
	while(bfs(s,t))
		memset(cur,0,sizeof(cur)),ans+=dfs(s,t,inf);
	return ans;
}
int main()
{
	int t,r,c,x,ks=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&r,&c);
		init(r+c);
		for(int i=1,pre=0;i<=r;i++,pre=x)
			scanf("%d",&x),link(0,i,x-pre-c);
		for(int i=1,pre=0;i<=c;i++,pre=x)
			scanf("%d",&x),link(r+i,r+c+1,x-pre-r);
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				eid[i][j]=ecnt,link(i,r+j,19);
		dinic(0,r+c+1);
		printf("Matrix %d\n",++ks);
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				printf("%d%c",e[eid[i][j]^1].w+1,j==c?'\n':' ');
	}
}