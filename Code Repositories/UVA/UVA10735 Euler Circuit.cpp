#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
const int maxn=105,maxm=505,inf=0x3f3f3f3f;
struct edge
{
	int u,v,w;
	edge(int u,int v,int w):u(u),v(v),w(w){}
};
vector<edge>e;
vector<int>g[maxn],ex[maxn];
stack<int>ans;
int ecnt,dis[maxn],cur[maxn];
int eu[maxm],ev[maxm],tag[maxm],pre[maxn];
int ind[maxn],otd[maxn],eid[maxm];
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
	memset(tag,0,sizeof(tag));
	memset(pre,0,sizeof(pre));
	memset(ind,0,sizeof(ind));
	memset(otd,0,sizeof(otd));
	for(int i=0;i<=n;i++) 
		g[i].clear(),ex[i].clear();
}
void dfs(int u)
{
	int& pt=pre[u];
	while(pt<(int)ex[u].size())
	{
		int v=ex[u][pt++];
		dfs(v),ans.push(v);
	}
}
int main()
{
	int T,n,m;
	char o[3];
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		init(n+1);
		int s=0,t=n+1,sum=0,ok=1;
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%s",&eu[i],&ev[i],o);
			if(o[0]=='U') tag[i]=1;
			ind[ev[i]]++,otd[eu[i]]++;
		}
		for(int i=1;i<=n;i++)
		{
			int deg=otd[i]-ind[i];
			if(deg&1) ok=false;
			deg>>=1;
			if(deg>0) link(s,i,deg),sum+=deg;
			else link(i,t,-deg);
		}
		for(int i=1;i<=m;i++)
			if(tag[i]) eid[i]=ecnt,link(eu[i],ev[i],1);
		if(!ok||dinic(s,t)!=sum) puts("No euler circuit exist");
		else
		{
			for(int i=1;i<=m;i++)
			{
				if(tag[i]&&e[eid[i]^1].w)
					swap(eu[i],ev[i]);
				ex[eu[i]].push_back(ev[i]);
			}
			dfs(1),putchar('1');
			while(!ans.empty())
				printf(" %d",ans.top()),ans.pop();
			puts("");
		}
		if(T) puts("");
	}
}