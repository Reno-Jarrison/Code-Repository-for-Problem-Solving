#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e3+5;
const double eps=1e-8;
const ll inf=1e12;
struct Point
{
	double x,y;
	Point(){}
	Point(double x,double y):x(x),y(y){}
}p[65];
typedef Point Vector;
struct Line   //两点式 p+tv
{
	Point p; Vector v;
	Line(Point p,Vector v):p(p),v(v){}
};
int dcmp(double x)
{	return fabs(x)<eps?0:x<0?-1:1; }
Vector operator - (Vector a,Vector b)
{	return Vector(a.x-b.x,a.y-b.y); }
double Cross(Vector a,Vector b)
{	return a.x*b.y-a.y*b.x; }
int LSIntersection(Line l,Point a,Point b)
{
	double c1=Cross(l.v,a-l.p),c2=Cross(l.v,b-l.p);
	if(dcmp(c1)*dcmp(c2)<0) return 1;   //规范相交 
	if(dcmp(c1)==0&&dcmp(c2)==0) return -1;   //重合
	if(dcmp(c1)==0||dcmp(c2)==0) return 2;   //端点在直线上 
	return 0;   //不相交 
}
int vx[35],vy[35];
ll dp[maxn][maxn],c;
void update(int l,int r)
{
	for(int i=l;i<=r;i++)
		for(int j=i;j<=r;j++)
			dp[i][j]=min(dp[i][j],c);
}
int main()
{
	int n,m;
	while(scanf("%d",&n)&&n)
	{
		double mx=0,my=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lf%lf",&p[i].x,&p[i].y);
			mx+=p[i].x,my+=p[i].y,p[i+n]=p[i];
		}
		Point mid=Point(mx/n,my/n),cur;
		scanf("%d",&m);
		memset(dp,0x3f,sizeof(dp));
		for(int i=1;i<=m;i++)
		{
			scanf("%lf%lf%lld",&cur.x,&cur.y,&c);
			vector<int>vec;
			for(int j=1;j<n*2;j++)
			{
				Line l=Line(p[j],p[j+1]-p[j]);
				if(LSIntersection(l,cur,mid)==1)
					vec.push_back(j);
			}
			vec.push_back(0);
			int las=-1;
			for(int i=0;i<vec.size()-1;i++)
			{
				if(las==-1) las=vec[i];
				if(vec[i+1]!=vec[i]+1)
					update(las,vec[i]),las=-1;
			}
		}
		for(int i=2;i<=n;i++)
			for(int l=1,r=l+i-1;r<2*n;l++,r++)
				for(int k=l;k<r;k++)
					dp[l][r]=min(dp[l][r],dp[l][k]+dp[k+1][r]);
		ll ans=inf;
		for(int i=1;i<=n;i++)
			ans=min(ans,dp[i][i+n-1]);
		if(ans<inf) printf("%lld\n",ans);
		else puts("Impossible.");
	}
}