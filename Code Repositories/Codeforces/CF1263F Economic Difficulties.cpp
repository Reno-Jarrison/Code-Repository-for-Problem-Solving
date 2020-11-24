#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+5,inf=0x3f3f3f3f;
vector<int>e[maxn];
int lbd[maxn],rbd[maxn],siz[maxn];
int mxv[maxn>>1][maxn>>1],dp[maxn>>1];
void dfs(int u)
{
	siz[u]=u>1;
	for(int v:e[u])
	{
		dfs(v),siz[u]+=siz[v];
		lbd[u]=min(lbd[u],lbd[v]);
		rbd[u]=max(rbd[u],rbd[v]);
	}
	int &ans=mxv[lbd[u]][rbd[u]];
	ans=max(ans,siz[u]);
}
int main()
{
	int n,m,x,t=2;
	scanf("%d",&n);
	while(t--)
	{
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
			e[i].clear(),lbd[i]=n,rbd[i]=1;
		for(int i=1;i<m;i++)
			scanf("%d",&x),e[x].push_back(i+1);
		for(int i=1;i<=n;i++)
			scanf("%d",&x),lbd[x]=rbd[x]=i;
		dfs(1);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			dp[i]=max(dp[i],dp[j-1]+mxv[j][i]);
	printf("%d",dp[n]);
}