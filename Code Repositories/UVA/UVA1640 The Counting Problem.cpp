#include<bits/stdc++.h>
using namespace std;
int num[10],dp[10][10][10],cnt[10];
int dfs(int pos,int sum,bool lim,bool lead,int bit)
{
	if(!pos) return sum;
	if(!lim&&!lead&&~dp[pos][sum][bit]) return dp[pos][sum][bit];
	int bound=lim?num[pos]:9,ans=0;
	for(int i=0;i<=bound;i++)
		ans+=dfs(pos-1,sum+((i||!lead)&&i==bit),lim&&i==bound,lead&&!i,bit);
	if(!lim&&!lead) dp[pos][sum][bit]=ans;
	return ans;
}
void query(int x,int delta)
{
	int len=0;
	while(x) num[++len]=x%10,x/=10;
	for(int i=0;i<=9;i++)
		cnt[i]+=delta*dfs(len,0,true,true,i);
}
int main()
{
	int l,r;
	memset(dp,-1,sizeof(dp));
	while(scanf("%d%d",&l,&r)&&l)
	{
		if(l>r) swap(l,r);
		memset(cnt,0,sizeof(cnt));
		query(r,1),query(l-1,-1);
		for(int i=0;i<=9;i++)
			printf("%d%c",cnt[i],i==9?'\n':' ');
	}
}