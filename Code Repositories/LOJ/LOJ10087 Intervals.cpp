#include<bits/stdc++.h>
#define maxn 50005
using namespace std;
struct edge
{ 	int nxt,val; };
vector<edge>e[maxn];
vector<edge>::iterator it;
int dist[maxn],vis[maxn]; 
inline void link(int u,int v,int w)
	{ e[u].push_back({v,w}); }
void spfa(int sta,int end)
{
	queue<int>q; 
	memset(dist,-0x3f,sizeof(dist));
	dist[sta]=0;
	q.push(sta);
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
				if(!vis[v]) vis[v]=1,q.push(v);
			}
		}
	}
	printf("%d",dist[end]);
}
int main()
{
	int n,a,b,c,maxm=0,minm=maxn;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		link(a,b+1,c);
		minm=min(minm,a);
		maxm=max(maxm,b+1);
	}
	for(int i=minm;i<maxm;i++)
		link(i,i+1,0),link(i+1,i,-1);
	spfa(minm,maxm);
	return 0;
}