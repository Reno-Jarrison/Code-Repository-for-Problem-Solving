#include<bits/stdc++.h>
using namespace std;
int num[15],dp[15][10];
int dfs(int pos,int las,bool lim,bool lead)
{
	if(!pos) return 1;
	if(!lim&&!lead&&~dp[pos][las]) return dp[pos][las];
	int bound=lim?num[pos]:9,ans=0;
	for(int i=0;i<=bound;i++)
	{
		if(!lead&&abs(las-i)<2) continue;
		ans+=dfs(pos-1,i,lim&&i==bound,lead&&i==0);
	}
	if(!lim&&!lead) dp[pos][las]=ans;
	return ans;
}
int query(int x)
{
	int len=0;
	while(x) num[++len]=x%10,x/=10;
	return dfs(len,0,true,true);
}
int main()
{
	int l,r;
	scanf("%d%d",&l,&r);
	memset(dp,-1,sizeof(dp));
	printf("%d",query(r)-query(l-1));
}