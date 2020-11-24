#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn=1e3+5,inf=0x3f3f3f3f;
struct edge
{
	int u,v,w;
	edge(int u,int v,int w):u(u),v(v),w(w){}
};
vector<edge>e;
vector<int>g[maxn];
int ecnt,dis[maxn],cur[maxn];
bool vis[maxn];
int win[maxn],a[maxn][maxn];
void link(int u,int v,int w)
{
	e.push_back(edge(u,v,w));
	e.push_back(edge(v,u,0));
	g[u].push_back(ecnt++);
	g[v].push_back(ecnt++);
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
void init()
{
	ecnt=0,e.clear();
	for(int i=0;i<=1000;i++) g[i].clear();
}
int main()
{
	int ks,n,x;
	scanf("%d",&ks);
	while(ks--)
	{
		scanf("%d",&n);
		int s=0,t=1000,tot=0,fst=1;
		for(int i=1;i<=n;i++)
			scanf("%d%d",&win[i],&x);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&a[i][j]),tot+=a[i][j];
		tot>>=1;
		for(int i=1;i<=n;i++)
		{
			init();
			int sum=win[i],ept=0,lose=0;
			for(int j=1;j<=n;j++) sum+=a[i][j];
			for(int j=1;j<=n;j++) 
			{
				if(sum<win[j]) { lose=true; break; }
				link(j,t,sum-win[j]);
			}
			if(lose) continue;
			for(int j=1;j<=n;j++)
				for(int k=j+1;k<=n;k++)
				{
					ept++;
					link(s,n+ept,a[j][k]);
					link(n+ept,j,inf);
					link(n+ept,k,inf);
				}
			if(dinic(s,t)==tot) 
			{
				if(!fst) putchar(' ');
				printf("%d",i),fst=0;
			}
		}
		puts("");
	}
}