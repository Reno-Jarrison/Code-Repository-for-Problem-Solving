#include<bits/stdc++.h>
#define ll long long
using namespace std;
int num[20];
ll dp[20][2][2];
ll dfs(int pos,int las,int len,bool lim,bool lead)
{
	if(!pos) return !lead&&las!=len;
	if(!lim&&!lead&&~dp[pos][las][len])
		return dp[pos][las][len];
	int bound=lim?num[pos]:9;
	ll ans=0;
	for(int i=0;i<=bound;i++)
	{
		int cur=i&1;
		if(!lead&&cur!=las&&las!=len)
			ans+=dfs(pos-1,cur,1,lim&&i==bound,false);
		else if(lead||cur==las)
			ans+=dfs(pos-1,cur,lead||(len+1)&1,lim&&i==bound,lead&&!i);
	}
	if(!lim&&!lead)
		dp[pos][las][len]=ans;
	return ans;
}
ll solve(ll x)
{
	int len=0;
	while(x)
		num[++len]=x%10,x/=10;
	return dfs(len,0,0,true,true);
}
int main()
{
	int n,ks=0;
	scanf("%d",&n);
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		ll l,r;
		scanf("%lld%lld",&l,&r);
		printf("Case #%d: %lld\n",++ks,solve(r)-solve(l-1));
	}
}