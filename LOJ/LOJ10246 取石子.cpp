#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=6e4+5;
int dp[55][maxn];
bool dfs(int a,int b)
{
	if(dp[a][b]!=-1) return dp[a][b];
	dp[a][b]=0;
	if(b==1) return dp[a][b]=dfs(a+1,0);
	if(a&&!dfs(a-1,b)) dp[a][b]=1;
	else if(b&&!dfs(a,b-1)) dp[a][b]=1;
	else if(a&&b&&!dfs(a-1,b+1)) dp[a][b]=1;
	else if(a>1&&!dfs(a-2,b+2+(b>0))) dp[a][b]=1;
	return dp[a][b];
}
int main()
{
	int t,x,n;
	scanf("%d",&t);
	memset(dp,-1,sizeof(dp));
	while(t--)
	{
		int a=0,b=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&x),x==1?a++:b+=x+1;
		if(b) b--;
		printf(dfs(a,b)?"YES":"NO"),puts("");
	}
}