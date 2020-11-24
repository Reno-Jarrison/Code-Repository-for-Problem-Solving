#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define sqr(x) ((x)*(x))
using namespace std;
const int maxn=1e3+5;
const double inf=1e15;
double dp[maxn][maxn];
struct node
{	int x,y; }p[maxn];
double getdist(int a,int b)
{	return sqrt(sqr(p[a].x-p[b].x)+sqr(p[a].y-p[b].y)); }
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dp[i][j]=inf;
		for(int i=1;i<=n;i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		dp[1][1]=0;
		for(int i=1;i<n;i++)
			for(int j=i;j<n;j++)
			{
				dp[i][j+1]=min(dp[i][j+1],dp[i][j]+getdist(j,j+1));
				dp[j][j+1]=min(dp[j][j+1],dp[i][j]+getdist(i,j+1));
			}
		double ans=inf;
		for(int i=1;i<n;i++)
			ans=min(ans,dp[i][n]+getdist(i,n));
		printf("%.2lf\n",ans);
	}
}
