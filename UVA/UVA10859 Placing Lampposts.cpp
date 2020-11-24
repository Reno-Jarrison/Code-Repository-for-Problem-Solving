#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
vector<int>e[maxn];
int dp1[maxn][2],dp2[maxn][2],vis[maxn];
void link(int u,int v)
{	e[u].push_back(v),e[v].push_back(u); }
void dfs(int u,int f)
{
	dp1[u][0]=dp2[u][0]=dp2[u][1]=0;
	dp1[u][1]=vis[u]=1;
	for(int v:e[u]) if(v!=f)
	{
		dfs(v,u);
		dp1[u][0]+=dp1[v][1];
		dp2[u][0]+=dp2[v][1];
		dp1[u][1]+=min(dp1[v][0],dp1[v][1]);
		if(dp1[v][0]<dp1[v][1])
			dp2[u][1]+=dp2[v][0];
		else if(dp1[v][1]<dp1[v][0])
			dp2[u][1]+=dp2[v][1]+1;
		else dp2[u][1]+=max(dp2[v][0],dp2[v][1]+1);
	}
}
int main()
{
	int t,n,m,u,v;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++) 
			e[i].clear(),vis[i]=0;
		for(int i=1;i<=m;i++)
			scanf("%d%d",&u,&v),link(u,v);
		int ans=0,cnt=0;
		for(int i=0;i<n;i++) if(!vis[i])
		{
			dfs(i,i);
			ans+=min(dp1[i][0],dp1[i][1]);
			if(dp1[i][0]<dp1[i][1])
				cnt+=dp2[i][0];
			else if(dp1[i][1]<dp1[i][0])
				cnt+=dp2[i][1];
			else cnt+=max(dp2[i][0],dp2[i][1]);
		}
		printf("%d %d %d\n",ans,cnt,m-cnt);
	}
}