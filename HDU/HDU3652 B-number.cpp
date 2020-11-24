#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[20][2][2][13],n;
int num[20];
ll dfs(int pos,bool las,bool ok,int mod,bool limit)
{
	if(!pos) return ok&&!mod;
	if(!limit&&~dp[pos][las][ok][mod]) 
		return dp[pos][las][ok][mod];
	int bound=limit?num[pos]:9;
	ll ans=0;
	for(int i=0;i<=bound;i++)
		ans+=dfs(pos-1,i==1,ok||(las&&i==3),(mod*10+i)%13,limit&&i==bound);
	if(!limit) dp[pos][las][ok][mod]=ans;
	return ans;
}
ll solve(ll n)
{
	int len=0;
	while(n) num[++len]=n%10,n/=10;
	return dfs(len,false,false,0,true);
}
int main()
{
	memset(dp,-1,sizeof(dp));
	while(~scanf("%lld",&n))
		printf("%lld\n",solve(n));
}