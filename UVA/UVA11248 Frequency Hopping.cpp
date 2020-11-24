#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm> 
#include<queue>
using namespace std;
const int maxn=105,inf=0x3f3f3f3f;
struct edge
{
	int u,v,w;
	edge(int u,int v,int w):u(u),v(v),w(w){}
	friend bool operator <(const edge& x,const edge& y)
	{	return x.u<y.u||(x.u==y.u&&x.v<y.v); }
};
int ecnt,ccnt,dep[maxn],vis[maxn],cur[maxn],res[20005];
vector<edge>e,ans;
vector<int>g[maxn],cut;
void init(int n)
{
	ecnt=ccnt=0;
	e.clear(),cut.clear(),ans.clear();
	for(int i=1;i<=n;i++) g[i].clear();
}
void link(int u,int v,int w)
{
	e.push_back(edge(u,v,w));
	e.push_back(edge(v,u,0));
	g[u].push_back(ecnt++);
	g[v].push_back(ecnt++);
}
bool bfs(int s,int t)
{
	memset(dep,inf,sizeof(dep));
	memset(vis,0,sizeof(vis));
	queue<int>q;
	q.push(s),vis[s]=true,dep[s]=0;
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=0;i<(int)g[u].size();i++)
		{
			int id=g[u][i],v=e[id].v;
			if(!vis[v]&&e[id].w)
				dep[v]=dep[u]+1,q.push(v),vis[v]=true;
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
		if(dep[v]==dep[u]+1&&(tmp=dfs(v,t,min(flow,w))))
		{
			e[id].w-=tmp,e[id^1].w+=tmp;
			flow-=tmp,ans+=tmp;
		}
	}
	return ans;
}
int dinic(int s,int t,int lim)
{
	int ans=0;
	while(bfs(s,t))
	{
		memset(cur,0,sizeof(cur)),ans+=dfs(s,t,inf);
		if(ans>=lim) break;
	}
	return ans;
}
int main()
{
	int n,m,c,u,v,w,cases=0;
	while(scanf("%d%d%d",&n,&m,&c)&&n)
	{
		init(n);
		for(int i=1;i<=m;i++)
			scanf("%d%d%d",&u,&v,&w),link(u,v,w);	
		printf("Case %d: ",++cases);
		int rflow=dinic(1,n,inf);
		if(rflow>=c) { puts("possible"); continue; }
		for(int i=0;i<ecnt;i++) 
		{
			if(!(i&1)&&!e[i].w) cut.push_back(i),ccnt++;
			res[i]=e[i].w;
		}
		for(int i=0;i<ccnt;i++)
		{
			for(int j=0;j<ecnt;j++) e[j].w=res[j];
			e[cut[i]].w=c;
			if(dinic(1,n,c-rflow)+rflow>=c) ans.push_back(e[cut[i]]);
		}
		int siz=ans.size();
		if(!siz) puts("not possible");
		else
		{
			sort(ans.begin(),ans.end()); 
			printf("possible option:");
			for(int i=0;i<siz;i++)
			{
				int u=ans[i].u,v=ans[i].v;
				printf("(%d,%d)%c",u,v,i==siz-1?'\n':',');
			}
		}
	}	
}