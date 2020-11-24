#include<bits/stdc++.h>
using namespace std;
int dp[45][45][45][45],a[45][5],top[5],vis[25],n;
int dfs(int cnt)
{
	int &val=dp[top[1]][top[2]][top[3]][top[4]];
	if(cnt==5) return 0;
	if(val!=-1) return val;
	val=0;
	for(int i=1;i<=4;i++)
	{
		if(top[i]==n) continue;
		top[i]++;
		if(vis[a[top[i]][i]])
		{
			vis[a[top[i]][i]]=false;
			val=max(val,dfs(cnt-1)+1);
			vis[a[top[i]][i]]=true;
		}
		else
		{
			vis[a[top[i]][i]]=true;
			val=max(val,dfs(cnt+1));
			vis[a[top[i]][i]]=false;	
		}
		top[i]--;
	}
	return val;
}
int main()
{
	while(scanf("%d",&n)&&n)
	{
		memset(dp,-1,sizeof(dp));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=4;j++)
				scanf("%d",&a[i][j]);
		printf("%d\n",dfs(0));
	}
}