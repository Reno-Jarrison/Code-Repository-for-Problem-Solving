#include<bits/stdc++.h>
#define ll long long
using namespace std;
int num[60],k;
ll dp[60][1500];
ll dfs(int pos,int sum,bool lim,int bit)
{
	if(!pos) return max(0,sum);
	if(!lim&&~dp[pos][sum]) return dp[pos][sum];
	int bound=lim?num[pos]:k-1;
	ll ans=0;
	for(int i=0;i<=bound;i++)
	{
		int delta=(bit==1?i*(pos-1):pos<bit?-i:i);
		ans+=dfs(pos-1,sum+delta,lim&&i==bound,bit);
	}
	if(!lim) dp[pos][sum]=ans;
	return ans;
}
ll query(ll x)
{
	int len=0;
	while(x) num[++len]=x%k,x/=k;
	ll ans=0;
	for(int i=1;i<=len;i++)
	{
		memset(dp,-1,sizeof(dp));
		ans+=dfs(len,0,true,i)*(i>1?-1:1);
	}
	return ans;
}
int main()
{
	ll l,r;
	scanf("%lld%lld%d",&l,&r,&k);
	printf("%lld",query(r)-query(l-1));
}