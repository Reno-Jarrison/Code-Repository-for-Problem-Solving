#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=3e3+5;
const ll inf=1e18;
ll w[maxn],x;
int siz[maxn];
vector<int>e[maxn];
struct node
{
	int cnt; ll sum;
	node(){}
	node(int c,ll s):cnt(c),sum(s){}
}dp[maxn][maxn],tmp[maxn][maxn];
bool operator <(const node& x,const node& y)
{	return x.cnt<y.cnt||(x.cnt==y.cnt&&x.sum<y.sum); }
void link(int u,int v)
{	e[u].push_back(v),e[v].push_back(u); }
void dfs(int u,int f)
{
	siz[u]=1,dp[u][1]=node(0,w[u]);
	for(int v:e[u]) if(v!=f)
	{
		dfs(v,u);
		for(int i=1;i<=siz[u]+siz[v];i++)
			tmp[u][i]=node(0,-inf);
		for(int i=1;i<=siz[u];i++)
			for(int j=1;j<=siz[v];j++)
			{
				int cnt=dp[u][i].cnt+dp[v][j].cnt;
				tmp[u][i+j]=max(tmp[u][i+j],
					node(cnt+(dp[v][j].sum>0),dp[u][i].sum));
				tmp[u][i+j-1]=max(tmp[u][i+j-1],
					node(cnt,dp[u][i].sum+dp[v][j].sum));
			}
		siz[u]+=siz[v];
		for(int i=1;i<=siz[u];i++)
			dp[u][i]=tmp[u][i];
	}
}
int main()
{
	int t,n,m,u,v;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		for(int i=1;i<=n;i++) 
			cin>>w[i],e[i].clear();
		for(int i=1;i<=n;i++)
			cin>>x,w[i]=x-w[i];
		for(int i=1;i<n;i++)
			cin>>u>>v,link(u,v);
		dfs(1,0),printf("%d\n",dp[1][m].cnt+(dp[1][m].sum>0));
	}
}