#include<bits/stdc++.h>
#define maxn 1505
using namespace std;
vector<int>e[maxn];
int dp[maxn][2],f[maxn];
void dfs(int rt)
{
	int len=e[rt].size();
	for(int i=0;i<len;i++)
	{
		int son=e[rt][i];
		if(f[rt]==son) continue;
		f[son]=rt;
		dfs(son);
		dp[rt][0]+=dp[son][1];
		dp[rt][1]+=min(dp[son][0],dp[son][1]);
	}
	dp[rt][1]++;
} 
int main()
{
	int n,id,k,r;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&id,&k);
		for(int j=0;j<k;j++)
			scanf("%d",&r),e[id].push_back(r),e[r].push_back(id); 
	}
	dfs(0);
	printf("%d",min(dp[0][0],dp[0][1]));
} 