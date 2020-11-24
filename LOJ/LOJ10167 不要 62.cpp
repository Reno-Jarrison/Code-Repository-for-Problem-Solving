#include<iostream>
#include<cstring>
using namespace std;
int dp[20][10],num[20];
int dfs(int pos,int pre,bool limit)
{
	if(!pos) return 1;
	if(!limit&&dp[pos][pre]!=-1) return dp[pos][pre];
	int bound=limit?num[pos]:9,ans=0;
	for(int i=0;i<=bound;i++)
	{
		if((pre==6&&i==2)||i==4) continue;
		ans+=dfs(pos-1,i,limit&&i==bound);
	}
	if(!limit) dp[pos][pre]=ans;
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
	int n,m;
	memset(dp,-1,sizeof(dp));
	while(cin>>n>>m&&n&&m)
		cout<<query(m)-query(n-1)<<endl;
}