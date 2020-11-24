#include<bits/stdc++.h>
using namespace std;
const int maxn=45;
const double pi=acos(-1);
double p[maxn],dp[maxn][maxn][maxn];
double len(double ang1,double ang2)
{
	double ang=abs(ang1-ang2);
	ang=min(ang,1-ang);
	return 2.0*sin(ang*pi);
}
double area(int i,int j,int k)
{
	double l1=len(p[i],p[j]),l2=len(p[j],p[k]),l3=len(p[i],p[k]);
	double hfc=(l1+l2+l3)/2.0;
	return sqrt(hfc*(hfc-l1)*(hfc-l2)*(hfc-l3));
}
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)&&n)
	{
		for(int i=1;i<=n;i++)
			scanf("%lf",&p[i]);
		memset(dp,0,sizeof(dp));
		for(int i=3;i<=m;i++)
			for(int l=1;l<=n;l++)
				for(int r=l+2;r<=n;r++)
					for(int j=l+1;j<r;j++)
						dp[i][l][r]=max(dp[i][l][r],dp[i-1][l][j]+area(l,r,j));
		double ans=0;
		for(int l=1;l<=n;l++)
			for(int r=l+1;r<=n;r++)
				ans=max(ans,dp[m][l][r]);
		printf("%.6lf\n",ans);
	}
}