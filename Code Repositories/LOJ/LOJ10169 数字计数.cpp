#include<cstdio>
#include<cstring>
#include<iostream>
#define ll long long
using namespace std;
ll dp[20][20],ans[10];
int num[20];
ll dfs(int pos,ll cnt,bool limit,bool lead,int bit)
{
	if(!pos) return cnt;
	if(!limit&&!lead&&dp[pos][cnt]!=-1) return dp[pos][cnt];
	int bound=limit?num[pos]:9;
	ll ans=0;
	for(int i=0;i<=bound;i++)
		ans+=dfs(pos-1,cnt+(i==bit&&(!lead||i)),limit&&i==bound,lead&&!i,bit);
	if(!limit&&!lead) dp[pos][cnt]=ans;
	return ans;
}
void query(ll x,int flag)
{
	int len=0;
	while(x) num[++len]=x%10,x/=10;
	for(int i=0;i<10;i++)
	{
		memset(dp,-1,sizeof(dp));
		ans[i]+=dfs(len,0,true,true,i)*flag;
	}
}
int main()
{
	ll a,b;
	scanf("%lld%lld",&a,&b);
	query(b,1);
	query(a-1,-1);
	for(int i=0;i<10;i++)
		printf("%lld ",ans[i]);
}