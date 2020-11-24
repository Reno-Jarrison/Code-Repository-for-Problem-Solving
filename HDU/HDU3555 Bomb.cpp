#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[20][2][2],n;
int num[20];
ll dfs(int pos,bool las,bool ok,bool limit)
{
	if(!pos) return ok;
	if(!limit&&~dp[pos][las][ok]) 
		return dp[pos][las][ok];
	int bound=limit?num[pos]:9;
	ll ans=0;
	for(int i=0;i<=bound;i++)
		ans+=dfs(pos-1,i==4,ok||(las&&i==9),limit&&i==bound);
	if(!limit) dp[pos][las][ok]=ans;
	return ans;
}
ll solve(ll n)
{
	int len=0;
	while(n) num[++len]=n%10,n/=10;
	return dfs(len,false,false,true);
}
int main()
{
	int t;
	memset(dp,-1,sizeof(dp));
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		printf("%lld\n",solve(n));
	}
}