#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e3+5,mod=1e9+7;
char s[maxn];
ll dp[2][maxn];
void update(ll& cur,ll val)
{	cur=(cur+val)%mod; }
int main()
{
	while(~scanf("%s",s+1))
	{
		int n=strlen(s+1)+1,tag=0;
		for(int i=0;i<=n;i++) dp[tag][i]=1;
		for(int i=1;i<n;i++)
		{
			tag^=1,memset(dp[tag],0,sizeof(dp[tag]));
			for(int j=0;j<=n-i;j++)
			{
				if(s[i]!='D')
				{
					update(dp[tag][0],dp[tag^1][j]);
					update(dp[tag][j],mod-dp[tag^1][j]);
				}
				if(s[i]!='I')
				{
					update(dp[tag][j],dp[tag^1][j]);
					update(dp[tag][n-i],mod-dp[tag^1][j]);
				}
			}
			for(int j=1;j<n-i;j++)
				update(dp[tag][j],dp[tag][j-1]);
		}
		printf("%lld\n",dp[tag][0]);
	}
}