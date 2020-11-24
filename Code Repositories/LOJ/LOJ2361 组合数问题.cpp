#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+5;
int dp[maxn][maxn],s[maxn][maxn];
void solve(int n,int k)
{
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=dp[i][i]=1;
		for(int j=1;j<=n;j++)
		{
			s[i][j]=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
			if(j>=i) continue;
			dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%k;
			if(!dp[i][j]) s[i][j]++;
		}
	}
}
int main()
{
	int t,k,n,m;
	scanf("%d%d",&t,&k);
	solve(2000,k);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		printf("%d\n",s[n][min(n,m)]);
	}
}