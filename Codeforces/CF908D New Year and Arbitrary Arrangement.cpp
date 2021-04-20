#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e3+5,mod=1e9+7;
int dp[maxn][maxn],k;
ll pa,pb,invpb,invp;
ll qpow(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%mod;
		a=a*a%mod,b>>=1;
	}
	return ans;
}
int dfs(int i,int j)
{
	if(j>=k) return j;
	if(i+j>=k) return (i+j+pa*invpb)%mod;
	if(~dp[i][j])
		return dp[i][j];
	return dp[i][j]=(pa*dfs(i+1,j)+pb*dfs(i,j+i))%mod*invp%mod;
}
int main()
{
	memset(dp,-1,sizeof(dp));
	scanf("%d%lld%lld",&k,&pa,&pb);
	invpb=qpow(pb,mod-2);
	invp=qpow(pa+pb,mod-2);
	printf("%d\n",dfs(1,0));
}