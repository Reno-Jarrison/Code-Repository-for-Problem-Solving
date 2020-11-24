#include<bits/stdc++.h>
using namespace std;
const double eps=1e-8,PI=acos(-1.0);
struct Point
{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
}p[105];
typedef Point Vector;
int dcmp(double x)
{	return fabs(x)<eps?0:x<0?-1:1; }
Vector operator +(Vector a,Vector b)
{	return Vector(a.x+b.x,a.y+b.y); }
Vector operator -(Vector a,Vector b)
{	return Vector(a.x-b.x,a.y-b.y); }
Vector operator *(Vector a,double p)
{	return Vector(a.x*p,a.y*p); }
double Dot(Vector a,Vector b) 
{	return a.x*b.x+a.y*b.y; }
double Cross(Vector a,Vector b)
{	return a.x*b.y-a.y*b.x; }
double Length(Vector a)
{	return sqrt(Dot(a,a)); }
double Angle(Vector a)
{	return atan2(a.y,a.x); }
double DAngle(Vector a,Vector b)
{	return acos(Dot(a,b)/Length(a)/Length(b)); }
bool cmp(Point a,Point b)
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
		Point mp;
		for(int i=1;i<=n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y),mp.x+=p[i].x,mp.y+=p[i].y;
		mp.x/=n,mp.y/=n;
		for(int i=1;i<=n;i++) p[i]=p[i]-mp;
		sort(p+1,p+n+1,cmp);
		p[0]=p[n];
		int ok=1;
		double len=Length(p[0]);
		for(int i=1;i<=n;i++)
			if(dcmp(Length(p[i])-len)||dcmp(DAngle(p[i],p[i-1])-2.0*PI/n)) ok=0;
		puts(ok?"YES":"NO");
	}
}