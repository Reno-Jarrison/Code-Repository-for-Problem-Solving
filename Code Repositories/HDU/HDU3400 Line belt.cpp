#include<bits/stdc++.h>
using namespace std;
struct Point
{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
}a,b,c,d;
double p,q,r;
double sqr(double x)
{	return x*x; }
double dis(Point a,Point b)
{	return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y)); }
Point mpoint(Point a,Point b)
{	return Point((a.x+b.x)/2,(a.y+b.y)/2); }
double g(Point s,Point t)
{	return dis(a,s)/p+dis(s,t)/r+dis(t,d)/q; }
double f(Point s)
{
	Point l=c,r=d;
	for(int i=1;i<=200;i++)
	{
		Point lmid=mpoint(l,r),rmid=mpoint(lmid,r);
		g(s,lmid)<g(s,rmid)?r=rmid:l=lmid;
	}
	return g(s,l);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y);
		scanf("%lf%lf%lf%lf",&c.x,&c.y,&d.x,&d.y);
		scanf("%lf%lf%lf",&p,&q,&r);
		Point l=a,r=b;
		for(int i=1;i<=200;i++)
		{
			Point lmid=mpoint(l,r),rmid=mpoint(lmid,r);
			f(lmid)<f(rmid)?r=rmid:l=lmid;
		}
		printf("%.2lf\n",f(l));
	}
}