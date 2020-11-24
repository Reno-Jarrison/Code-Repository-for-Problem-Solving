#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
struct edge
{ int nxt,val; };
int r[25],num[25],dist[25],vis[25],cnt[25];
vector<edge>e[25];
vector<edge>::iterator it;
inline void link(int u,int v,int w)
{ e[u].push_back({v,w}); }
bool spfa(int n)
{
	queue<int>q;
	memset(dist,-0x3f,sizeof(dist));
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	q.push(0),dist[0]=0;
	vis[0]=cnt[0]=1;
	while(!q.empty())
	{
		int u=q.front();
		q.pop(),vis[u]=0;
		for(it=e[u].begin();it!=e[u].end();it++)
		{
			int v=(*it).nxt,w=(*it).val;
			if(dist[v]<dist[u]+w)
			{
				dist[v]=dist[u]+w;
				if(!vis[v]) vis[v]=1,cnt[v]++,q.push(v);
				if(cnt[v]==25) return false;
			}
		}
	}
	return dist[24]==n;
}
int main()
{
	int t,n,x;
	scanf("%d",&t);
	while(t--)
	{
		bool flag=false;
		memset(num,0,sizeof(num));
		for(int i=1;i<=24;i++)
			scanf("%d",&r[i]);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&x),num[x+1]++;
		for(int ans=0;ans<=n;ans++)
		{
			for(int i=0;i<=24;i++) e[i].clear();
			for(int i=1;i<=24;i++)
			{
				link(i-1,i,0),link(i,i-1,-num[i]);
				if(i>=8) link(i-8,i,r[i]);
				else link(i+16,i,r[i]-ans);
			}
			link(0,24,ans);
			if(spfa(ans)) { flag=true; break; }
		}
		if(flag) printf("%d\n",dist[24]);
		else printf("No Solution\n");
	}
}