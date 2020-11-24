#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn=3e3,inf=0x3f3f3f3f;
struct edge
{
	int u,v,w;
	edge(int u,int v,int w):u(u),v(v),w(w){}
};
vector<edge>e;
vector<int>g[maxn];
int ecnt,dis[maxn],cur[maxn];
bool vis[maxn];
void link(int u,int v,int w)
{
	e.push_back(edge(u,v,w));
	e.push_back(edge(v,u,0));
	g[u].push_back(ecnt++);
	g[v].push_back(ecnt++);
}
bool bfs(int s,int t)
{
	memset(vis,0,sizeof(vis));
	memset(dis,inf,sizeof(dis));
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
void init(int n)
{
	ecnt=0,e.clear();
	for(int i=0;i<=n;i++) g[i].clear();
}
char str[maxn][maxn];
int main()
{
	int T,r,c,d,f,b;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d%d",&c,&r,&d,&f,&b);
		int ans=0,s=0,t=r*c+1;
		init(r*c+1);
		for(int i=1;i<=r;i++)
			scanf("%s",str[i]+1);
		for(int i=1;i<=r;i++)
		{
			if(str[i][1]=='.') str[i][1]='#',ans+=f;
			if(str[i][c]=='.') str[i][c]='#',ans+=f;
		}
		for(int i=1;i<=c;i++)
		{
			if(str[1][i]=='.') str[1][i]='#',ans+=f;
			if(str[r][i]=='.') str[r][i]='#',ans+=f;
		}
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
			{
				int id=(i-1)*c+j,uid=id-c,lid=id-1;
				if(i>1) link(uid,id,b),link(id,uid,b);
				if(j>1) link(lid,id,b),link(id,lid,b);
				if(str[i][j]=='#')
					link(s,id,(i==1||i==r||j==1||j==c)?inf:d);
				else link(id,t,f);
			}
		printf("%d\n",ans+dinic(s,t));
	}
}