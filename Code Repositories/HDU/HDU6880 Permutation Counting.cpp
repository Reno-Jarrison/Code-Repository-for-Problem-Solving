#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e3+5;
const ll mod=1e9+7;
ll dp[2][maxn];
void add(ll& a,ll b)
{	a=(a+b)%mod; }
int main()
{
	int t,n,b;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int tag=0;
		fill(dp[0],dp[0]+n+1,1);
		for(int i=1;i<n;i++,tag^=1)
		{
			fill(dp[tag^1],dp[tag^1]+n,0);
			scanf("%d",&b);
			for(int j=0;j<=n-i;j++)
			{
				if(!b)
				{
					add(dp[tag^1][0],dp[tag][j]);
					add(dp[tag^1][j],mod-dp[tag][j]);
				}
				else
				{
					add(dp[tag^1][j],dp[tag][j]);
					add(dp[tag^1][n-i],mod-dp[tag][j]);
				}
			}
			for(int j=1;j<n-i;j++)
				add(dp[tag^1][j],dp[tag^1][j-1]);
		}
		printf("%lld\n",n==1?1:dp[tag][0]);
	}
}