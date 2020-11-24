#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int base=2500;
int num[20];
ll dp[20][20][5000],l,r;
ll dfs(int pos,int mid,int sum,bool limit)
{
	if(!pos) return sum==base;
	if(!limit&&~dp[pos][mid][sum])
		return dp[pos][mid][sum];
	int bound=limit?num[pos]:9;
	ll ans=0;
	for(int i=0;i<=bound;i++)
		ans+=dfs(pos-1,mid,sum+i*(pos-mid),limit&&i==bound);
	if(!limit) dp[pos][mid][sum]=ans;
	return ans;
}
ll solve(ll x)
{
	if(x<0) return 0;
	int len=0;
	while(x) num[++len]=x%10,x/=10;
	ll ans=0;
	for(int i=1;i<=len;i++)
		ans+=dfs(len,i,base,true);
	return ans-len+1;
}
int main()
{
	int t;
	scanf("%d",&t);
	memset(dp,-1,sizeof(dp));
	while(t--)
	{
		scanf("%lld%lld",&l,&r);
		printf("%lld\n",solve(r)-solve(l-1));
	}
}