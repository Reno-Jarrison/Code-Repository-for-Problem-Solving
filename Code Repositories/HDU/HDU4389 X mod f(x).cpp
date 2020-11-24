#include<bits/stdc++.h>
using namespace std;
int dp[11][90][90][90],l,r;
int num[11];
int dfs(int pos,int sum,int mod,int tot,bool limit)
{
	if(!pos) return sum==tot&&!mod;
	if(!limit&&~dp[pos][sum][mod][tot]) 
		return dp[pos][sum][mod][tot];
	int bound=limit?num[pos]:9;
	int ans=0;
	for(int i=0;i<=bound;i++)
		ans+=dfs(pos-1,sum+i,(mod*10+i)%tot,tot,limit&&i==bound);
	if(!limit) dp[pos][sum][mod][tot]=ans;
	return ans;
}
int solve(int n)
{
	int len=0;
	while(n) num[++len]=n%10,n/=10;
	int ans=0;
	for(int i=1;i<=81;i++)
		ans+=dfs(len,0,0,i,true);
	return ans;
}
int main()
{
	int t,ks=0;
	memset(dp,-1,sizeof(dp));
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&l,&r);
		printf("Case %d: %d\n",++ks,solve(r)-solve(l-1));
	}
}