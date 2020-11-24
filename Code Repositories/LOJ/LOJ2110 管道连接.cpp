#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5,inf=0x3f3f3f3f;
struct edge
{
	int to,w;
	edge(int to,int w):to(to),w(w){}
};
vector<edge>e[maxn];
vector<int>vtx[15];
int dp1[maxn][1<<10],dp2[1<<10],idx[maxn],vis[maxn];
void link(int u,int v,int w)
{	e[u].push_back(edge(v,w)),e[v].push_back(edge(u,w)); }
queue<int>que;
void spfa(int s)
{
	while(!que.empty())
	{
		int u=que.front(); que.pop();
		vis[u]=false;
		for(int i=0;i<(int)e[u].size();i++)
		{
			int v=e[u][i].to,w=e[u][i].w;
			if(dp1[v][s]>dp1[u][s]+w)
			{
				dp1[v][s]=dp1[u][s]+w;
				if(!vis[v]) que.push(v),vis[v]=true;
			}
		}
	}
}
void steiner(int n,int k)
{
    for(int s=1;s<(1<<k);s++)
    {
        for(int i=1;i<=n;i++)
            for(int sub=s;sub;sub=(sub-1)&s)
            {
                dp1[i][s]=min(dp1[i][s],dp1[i][sub]+dp1[i][s^sub]);
                if(dp1[i][s]<inf&&!vis[i]) que.push(i),vis[i]=true;
            }
        spfa(s);
        for(int i=1;i<=n;i++)
    		dp2[s]=min(dp2[s],dp1[i][s]);
    }
}
bool check(int s,int k)
{
	for(int i=0;i<k;i++) if(s&(1<<i))
		for(int j=0;j<(int)vtx[idx[i]].size();j++)
			if(!(s&(1<<vtx[idx[i]][j]))) return false;
	return true;
}
int main()
{
	int n,m,k,u,v,w,id;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&u,&v,&w),link(u,v,w);
	memset(dp1,inf,sizeof(dp1));
	memset(dp2,inf,sizeof(dp2));
	for(int i=0;i<k;i++)
	{
		scanf("%d%d",&id,&u),vtx[id].push_back(i);
		dp1[u][1<<i]=0,idx[i]=id;
	}
	steiner(n,k);
	for(int s=1;s<(1<<k);s++)
		for(int sub=s;sub;sub=(sub-1)&s)
			if(check(sub,k)&&check(s^sub,k))
				dp2[s]=min(dp2[s],dp2[sub]+dp2[s^sub]);
	printf("%d",dp2[(1<<k)-1]);
}