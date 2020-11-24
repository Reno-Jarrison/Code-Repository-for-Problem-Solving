#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int dp1[maxn][maxn],dp2[maxn],w[maxn],m;
vector<int>e[maxn];
void dfs(int u)
{
	dp1[u][1]=w[u];
	for(int v:e[u])
	{
		dfs(v);
		for(int i=m;i;i--)
			for(int j=0;j<i;j++)
				dp1[u][i]=max(dp1[u][i],dp1[u][i-j]+dp1[v][j]);
	}
}
int main()
{
	int n,f;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&f,&w[i]),e[f].push_back(i);
	for(int rt:e[0])
	{
		dfs(rt);
		for(int i=m;i;i--)
			for(int j=0;j<=i;j++)
				dp2[i]=max(dp2[i],dp2[i-j]+dp1[rt][j]);
	}
	printf("%d\n",dp2[m]);
}