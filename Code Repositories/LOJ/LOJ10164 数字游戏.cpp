#include<bits/stdc++.h>
using namespace std;
int num[15],dp[15][10];
int dfs(int pos,int las,bool lim)
{
	if(!pos) return 1;
	if(!lim&&~dp[pos][las]) return dp[pos][las];
	int bound=lim?num[pos]:9,ans=0;
	for(int i=las;i<=bound;i++)
		ans+=dfs(pos-1,i,lim&&i==bound);
	if(!lim) dp[pos][las]=ans;
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
	int l,r;
	memset(dp,-1,sizeof(dp));
	while(~scanf("%d%d",&l,&r))
		printf("%d\n",query(r)-query(l-1));
}