#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=305,inf=0x3f3f3f3f;
struct edge
{
	int u,v,w;
	edge(int u,int v,int w):u(u),v(v),w(w){}
};
vector<edge>e;
vector<int>g[maxn];
int ecnt,sum,dis[maxn],cur[maxn],eid[maxn][25];
int in[maxn],out[maxn],llim[maxn][25],ulim[maxn][25];
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
				dis[v]=dis[u]+1,q.push(v),vis[v]=true;
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
void init(int n,int m)
{
	ecnt=sum=0,e.clear();
	for(int i=0;i<=n+m+3;i++) g[i].clear();
	memset(in,0,sizeof(in));
	memset(out,0,sizeof(out));
	memset(llim,0,sizeof(llim));
	memset(ulim,inf,sizeof(ulim));
}
void setlim(int r,int c,int l,int u)
{
	llim[r][c]=max(llim[r][c],l);
	ulim[r][c]=min(ulim[r][c],u);
}
int main()
{
	int t,n,m,low,upp;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		init(n,m);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&low),link(0,i,0);
			out[0]+=low,in[i]+=low;
		}
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&low),link(n+i,m+n+1,0);
			out[n+i]+=low,in[m+n+1]+=low;
		}
		int c,r,q,v; char o[3];
		scanf("%d",&c);
		while(c--)
		{
			scanf("%d%d%s%d",&r,&q,o,&v);
			if(o[0]=='<') low=0,upp=v-1;
			else if(o[0]=='>') low=v+1,upp=inf;
			else low=upp=v;
			if(r&&q) setlim(r,q,low,upp);
			else if(r) for(int i=1;i<=m;i++)
				setlim(r,i,low,upp);
			else if(q) for(int i=1;i<=n;i++)
				setlim(i,q,low,upp);
			else for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
					setlim(i,j,low,upp);
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				low=llim[i][j];
				link(i,n+j,ulim[i][j]-low);
				eid[i][j]=ecnt-1;
				out[i]+=low,in[n+j]+=low;
			}
		for(int i=0;i<=n+m+1;i++)
			link(n+m+2,i,in[i]),link(i,n+m+3,out[i]),sum+=in[i];
		link(n+m+1,0,inf);
		if(dinic(n+m+2,n+m+3)<sum) puts("IMPOSSIBLE");
		else for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				printf("%d ",e[eid[i][j]].w+llim[i][j]);
			puts("");
		}
		if(t) puts("");
	}
}