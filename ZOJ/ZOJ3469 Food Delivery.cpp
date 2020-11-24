#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e3+5;
const ll inf=1e18;
pair<int,int>p[maxn];
ll s[maxn],dp[maxn][maxn][2];
ll sum(int l,int r)
{	return s[r]-s[l-1]; }
void update(ll& cur,ll val)
{	cur=min(cur,val); }
int main()
{
	int n,v,x;
	while(~scanf("%d%d%d",&n,&v,&x))
	{	
		for(int i=1;i<=n;i++)
			scanf("%d%d",&p[i].first,&p[i].second);
		sort(p+1,p+n+1);
		for(int i=1;i<=n;i++)
			s[i]=s[i-1]+p[i].second;
		ll tot=s[n];
		for(int i=1;i<=n;i++)
			dp[i][i][0]=dp[i][i][1]=tot*abs(x-p[i].first)*v;
		for(int i=2;i<=n;i++)
			for(int l=1,r=l+i-1;r<=n;l++,r++)
			{
				dp[l][r][0]=dp[l][r][1]=inf;
				ll costl=(tot-sum(l+1,r))*v,costr=(tot-sum(l,r-1))*v;
				update(dp[l][r][0],dp[l+1][r][0]+costl*(p[l+1].first-p[l].first));
				update(dp[l][r][0],dp[l+1][r][1]+costl*(p[r].first-p[l].first));
				update(dp[l][r][1],dp[l][r-1][1]+costr*(p[r].first-p[r-1].first));
				update(dp[l][r][1],dp[l][r-1][0]+costr*(p[r].first-p[l].first));
			}
		printf("%lld\n",min(dp[1][n][0],dp[1][n][1]));
	}
}