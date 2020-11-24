#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=5e3+5;
int cnt[maxn],ans[maxn];
struct Point
{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y) {}
}p1[maxn],p2[maxn];
typedef Point Vector;
const double eps=1e-10;
Vector operator -(Vector a,Vector b)
{	return Vector(a.x-b.x,a.y-b.y); }
double Cross(Vector a,Vector b)
{	return a.x*b.y-a.y*b.x; }
bool operator <(const Vector& a,const Vector& b)
{	return a.x<b.x||(a.x==b.x&&a.y<b.y); }
bool operator ==(const Vector& a,const Vector& b)
{	return fabs(a.x-b.x)<eps&&fabs(a.y-b.y)<eps; }
int main()
{
	int n,m;
	double x1,y1,x2,y2,u,l,x,y;
	while(~scanf("%d",&n)&&n)
	{
		memset(cnt,0,sizeof(cnt));
		memset(ans,0,sizeof(ans));
		scanf("%d%lf%lf%lf%lf",&m,&x1,&y1,&x2,&y2);
		p1[n]=Point(x2,y1),p2[n]=Point(x2,y2);
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&u,&l);
			p1[i]=Point(u,y1),p2[i]=Point(l,y2);
		}
		sort(p1,p1+n),sort(p2,p2+n);
		for(int i=0;i<m;i++)
		{
			scanf("%lf%lf",&x,&y);
			Point p(x,y); 
			int pt=0;
			while(Cross(p1[pt]-p2[pt],p-p1[pt])<0) pt++;
			cnt[pt]++;
		}
		for(int i=0;i<=n;i++)
			ans[cnt[i]]++;
		printf("Box\n");
		for(int i=1;i<=m;i++)
			if(ans[i]) printf("%d: %d\n",i,ans[i]);
	}
}
