#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int dp[maxn];
int dfs(int n)
{
	if(n==0) return 0;
	if(~dp[n])
		return dp[n];
	int ans=0;
	if(n>1) ans|=!dfs(n-1);
	if(n>5) ans|=!dfs(n-5);
	if(n>13) ans|=!dfs(n-13);
	return dp[n]=ans;
}
int main()
{
	int n;
	scanf("%d",&n);
	memset(dp,-1,sizeof(dp));
	printf("%d\n",dfs(n)?1:2);
}