#include<bits/stdc++.h>
using namespace std;
int dp[100][10];
int dfs(int a,int d)
{
	if(a<0) return 0;
	if(!a) return 1;
	if(~dp[a][d])
		return dp[a][d];
	int ans=0;
	for(int i=0;i<=9;i++)
		ans|=dfs(a-d*10-i,d)|dfs(a-d-i*10,d);
	return dp[a][d]=ans;
}
int main()
{
	int t,q,d,a;
	scanf("%d",&t);
	memset(dp,-1,sizeof(dp));
	while(t--)
	{
		scanf("%d%d",&q,&d);
		while(q--)
		{
			scanf("%d",&a);
			puts(a>=d*10||dfs(a,d)?"YES":"NO");
		}
	}
}