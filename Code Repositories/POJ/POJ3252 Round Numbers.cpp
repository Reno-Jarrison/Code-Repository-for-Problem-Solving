#include<cstdio>
#include<cstring>
using namespace std;
int dp[35][35][35],num[35];
int dfs(int pos,int cnt0,int cnt1,bool limit,bool lead)
{
	if(!pos) return cnt0>=cnt1;
	if(!limit&&!lead&&~dp[pos][cnt0][cnt1])
		return dp[pos][cnt0][cnt1];
	int bound=limit?num[pos]:1,ans=0;
	for(int i=0;i<=bound;i++)
	{
		int nxt0=cnt0+(i==0&&!lead);
		int nxt1=cnt1+(i==1);
		ans+=dfs(pos-1,nxt0,nxt1,limit&&i==bound,lead&&!i);
	}
	if(!limit&&!lead) dp[pos][cnt0][cnt1]=ans;
	return ans;
}
int solve(int x)
{
	if(x<0) return 0;
	int len=0;
	while(x) num[++len]=x&1,x>>=1;
	return dfs(len,0,0,true,true);
}
int main()
{
	int l,r;
	memset(dp,-1,sizeof(dp));
	scanf("%d%d",&l,&r);
	printf("%d\n",solve(r)-solve(l-1));
}