#include<cstdio>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=505,inf=0x3f3f3f3f;
struct edge
{
	int to,w,tag;
	edge(int to,int w,int tag):to(to),w(w),tag(tag){}
};
struct node
{
	int id,w;
	node(int id,int w):id(id),w(w){}
};
bool operator <(const node& x,const node& y)
{	return x.w>y.w; }
vector<edge>e[maxn];
stack<int>path;
int temp[maxn],dist[maxn],tag;
bool vis[maxn];
int dijkstra(int beg,int end,int flag)
{
	memset(dist,inf,sizeof(dist));
	memset(vis,0,sizeof(vis));
	priority_queue<node>q;
	dist[beg]=0,q.push(node(beg,0)),tag=-1;
	while(!q.empty())
	{
		int u=q.top().id; q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int i=0;i<(int)e[u].size();i++)
		{
			edge tmp=e[u][i]; int v=tmp.to;
			if(vis[v]||(tmp.tag&&tmp.tag!=flag)) continue;
			if(dist[v]>dist[u]+tmp.w)
			{
				dist[v]=dist[u]+tmp.w,temp[v]=u;
				q.push(node(v,dist[v]));
				if(tmp.tag) tag=u;
			}
		}
	}
	return dist[end];
}
void getpath(int beg,int end)
{
	int pt=end;
	while(!path.empty()) path.pop();
	while(pt!=beg) path.push(pt),pt=temp[pt];
	path.push(beg);
}
int main()
{
	int n,beg,end,m,k,u,v,w,cases=0;
	while(~scanf("%d%d%d",&n,&beg,&end))
	{
		for(int i=1;i<=n;i++) e[i].clear();
		int ans=inf,sta=-1;
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			e[u].push_back(edge(v,w,0));
			e[v].push_back(edge(u,w,0));
		}
		scanf("%d",&k);
		for(int i=1;i<=k;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			e[u].push_back(edge(v,w,i));
			e[v].push_back(edge(u,w,i));
		}
		for(int i=0;i<=k;i++)
		{
			int d=dijkstra(beg,end,i);
			if(ans>d) ans=d,sta=tag,getpath(beg,end);
		}
		if(cases++) puts("");
		while(path.top()!=end) printf("%d ",path.top()),path.pop();
		printf("%d\n",end);
		if(sta==-1) printf("Ticket Not Used\n");
		else printf("%d\n",sta);
		printf("%d\n",ans);
	}
}