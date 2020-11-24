#include<cstdio>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
const int maxn=55;
struct Point
{
	int id;
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
	void read()
	{	scanf("%d%lf%lf",&id,&x,&y); }
}p[maxn],pt;
typedef Point Vector;
const double eps=1e-10;
int dcmp(double x)
{	return fabs(x)<eps?0:x<0?-1:1; }
bool operator <(const Point& a,const Point& b)
{	return a.y<b.y||(a.y==b.y&&a.x<b.x); }
bool operator ==(const Point& a,const Point& b)
{	return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0; }

double Angle(Point a)
{	return atan2(a.y,a.x); }
Vector operator -(Vector a,Vector b)
{	return Vector(a.x-b.x,a.y-b.y); }
double Cross(Vector a,Vector b)
{	return a.x*b.y-a.y*b.x; }
double Dot(Vector a,Vector b)
{	return a.x*b.x+a.y*b.y; }
double Length(Vector a)
{	return sqrt(Dot(a,a)); }
double Dist(Point a,Point b)
{	return Length(a-b); }
bool cmp1(Point a,Point b)
{
	Vector v1=a-pt,v2=b-pt; 
	int flag=dcmp(Cross(v1,v2));
	if(!flag) return Dist(a,pt)<Dist(b,pt);
	return flag>0;
}
bool cmp2(Point a,Point b)
{
	double ang1=Angle(a),ang2=Angle(b);
	return ang1!=ang2?ang1<ang2:a.x<b.x; 
}

int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			p[i].read();
		sort(p,p+n);
		pt=p[0];
		printf("%d %d",n,pt.id);
		for(int i=1;i<n;i++)
		{
			sort(p+i,p+n,cmp1);
			pt=p[i];
			printf(" %d",pt.id);
		}
		printf("\n");
	} 
}
