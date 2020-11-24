#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=3e3+5;
ll v[maxn][maxn],dp[maxn][maxn][4],x;
void update(ll& cur,ll val)
{	cur=max(cur,val); }
int main()
{
	int n,m,p,r,c;
	scanf("%d%d%d",&n,&m,&p);
	for(int i=1;i<=p;i++)
		scanf("%d%d%lld",&r,&c,&x),v[r][c]=x;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(i>1) for(int k=0;k<=3;k++)
				update(dp[i][j][0],dp[i-1][j][k]);
			if(j>1) for(int k=0;k<=3;k++)
				update(dp[i][j][k],dp[i][j-1][k]);
			if(v[i][j]) for(int k=3;k;k--)
				update(dp[i][j][k],dp[i][j][k-1]+v[i][j]);
		}
	ll ans=0;
	for(int i=0;i<=3;i++)
		update(ans,dp[n][m][i]);
	printf("%lld\n",ans);
}