#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int dp[20][105],num[20],mod;
int dfs(int pos,int sum,bool limit)
{
	if(!pos) return sum==0;
	if(!limit&&dp[pos][sum]!=-1) return dp[pos][sum];
	int bound=limit?num[pos]:9,ans=0;
	for(int i=0;i<=bound;i++)
	{
		ans+=dfs(pos-1,(sum+i)%mod,limit&&i==bound); 
	}
	if(!limit) dp[pos][sum]=ans;
	return ans;
}
int query(int x)
{
	int len=0;
	while(x) num[++len]=x%10,x/=10;
	return dfs(len,0,true);
}
int main()
{
	int a,b;
	while(scanf("%d%d%d",&a,&b,&mod)!=EOF)
	{
		memset(dp,-1,sizeof(dp));
		printf("%d\n",query(b)-query(a-1));
	}
}