#include<bits/stdc++.h>
using namespace std;
const int maxn=55;
struct point
{	int x,y; }p[maxn];
int dp[maxn][maxn*maxn];
bool operator <(const point& a,const point& b)
{	return a.y*b.x>a.x*b.y; }
int main()
{
	int t,n,m,mxv,ks=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(dp,-0x3f,sizeof(dp));
		dp[0][0]=mxv=0;
		for(int i=1;i<=n;i++)
			scanf("%d%d",&p[i].x,&p[i].y),mxv+=p[i].y;
		sort(p+1,p+n+1);
		for(int i=1;i<=n;i++)
			for(int j=m;j;j--)
				for(int k=mxv;k>=p[i].y;k--)
					dp[j][k]=max(dp[j][k],dp[j-1][k-p[i].y]+p[i].x*(2*k-p[i].y));
		int ans=0;
		for(int i=0;i<=mxv;i++)
			ans=max(ans,dp[m][i]);
		printf("Case %d: %d\n",++ks,ans);
	}
}