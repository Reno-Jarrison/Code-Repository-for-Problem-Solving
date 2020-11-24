#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int maxn=5e3+5,inf=0x3f3f3f3f;
struct edge
{
	int u,v,w;
	edge(int u,int v,int w):u(u),v(v),w(w){}	
};
int ecnt,dis[maxn],cur[maxn],eu[maxn],ev[maxn];
bool vis[maxn],flag[maxn];
vector<edge>e;
vector<int>g[maxn];
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
int dinic(int s,int t,int lim)
{
	int ans=0;
	while(bfs(s,t))
	{
		memset(cur,0,sizeof(cur)),ans+=dfs(s,t,lim-ans);
		if(ans==lim) break; 
	}
	return ans;
}
void init(int n)
{
	ecnt=0,e.clear();
	for(int i=0;i<n;i++) g[i].clear();
}
int main()
{
	int n,m,k,s,t;
	while(~scanf("%d%d%d%d%d",&n,&m,&k,&s,&t))
	{
		for(int i=0;i<m;i++)
			scanf("%d%d",&eu[i],&ev[i]),eu[i]--,ev[i]--;
		init(n),s--,t--;
		int ans=1,flow=0;
		while(true)
		{
			for(int i=ans*n;i<(ans+1)*n;i++)
				g[i].clear();
			for(int i=0;i<n;i++)
				link(i+(ans-1)*n,i+ans*n,inf);
			for(int i=0;i<m;i++)
			{
				link(eu[i]+(ans-1)*n,ev[i]+ans*n,1);
				link(ev[i]+(ans-1)*n,eu[i]+ans*n,1);
			}
			flow+=dinic(s,t+n*ans,k-flow);
			if(flow==k) break;
			else ans++;
		}
		printf("%d\n",ans);
		int pt=0,w1,w2;
		vector<int>pos(k,s);
		for(int i=1;i<=ans;i++)
		{
			pt+=(n<<1);
			vector<int>v1,v2;
			memset(flag,0,sizeof(flag));
			for(int i=0;i<m;i++)
			{
				w1=e[pt^1].w,pt+=2;
				w2=e[pt^1].w,pt+=2;
				if(w1&&!w2) v1.push_back(eu[i]),v2.push_back(ev[i]);
				if(!w1&&w2) v1.push_back(ev[i]),v2.push_back(eu[i]);
			}
			printf("%d",(int)v1.size());
			for(int i=0;i<(int)v1.size();i++)
				for(int j=0;j<k;j++)
					if(!flag[j]&&v1[i]==pos[j])
					{
						pos[j]=v2[i],flag[j]=true;
						printf(" %d %d",j+1,pos[j]+1);
						break;
					}
			puts("");
		}
	}
}