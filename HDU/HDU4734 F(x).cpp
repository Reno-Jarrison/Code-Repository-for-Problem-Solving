#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int num[15],dp[15][maxn],pow2[15];
int dfs(int pos,int sum,bool lim)
{
	if(!pos||sum<0) return sum>=0;
	if(!lim&&~dp[pos][sum]) return dp[pos][sum];
	int bound=lim?num[pos]:9,ans=0;
	for(int i=0;i<=bound;i++)
		ans+=dfs(pos-1,sum-i*pow2[pos],lim&&i==bound);
	if(!lim) dp[pos][sum]=ans;
	return ans;
}
int solve(int x,int sum)
{
	int cnt=0;
	while(x) num[++cnt]=x%10,x/=10;
	return dfs(cnt,sum,1);
}
void init()
{
	memset(dp,-1,sizeof(dp));
	pow2[1]=1;
	for(int i=2;i<=12;i++)
		pow2[i]=pow2[i-1]*2;
}
int main()
{
	init();
	int t,a,b,ks=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&a,&b);
		int fx=0;
		for(int i=1;i<=12;i++)
			fx+=a%10*pow2[i],a/=10;
		printf("Case #%d: %d\n",++ks,solve(b,fx));
	}
}