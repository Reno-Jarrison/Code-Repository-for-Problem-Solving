#include<cstdio>
#include<cmath>
using namespace std;
struct Point
{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
	void read()
	{	scanf("%lf%lf",&x,&y); }
};
typedef Point Vector; 
struct Line
{
	Point p; Vector v;
	Line(Point p,Vector v):p(p),v(v){}
};
const double eps=1e-10;
int dcmp(double x)
{	return fabs(x)<eps?0:x<0?-1:1; }

Vector operator +(Vector a,Vector b) { return Vector(a.x+b.x,a.y+b.y); }
Vector operator -(Vector a,Vector b) { return Vector(a.x-b.x,a.y-b.y); }
Vector operator *(Vector a,double p) { return Vector(a.x*p,a.y*p); }
double Cross(Vector a,Vector b)
{	return a.x*b.y-a.y*b.x; }

int IsLineIntersection(Line l1,Line l2)
{
	if(dcmp(Cross(l1.v,l2.v))) return 1;
	else return dcmp(Cross(l2.p-l1.p,l1.v))?0:-1;
}
Point LineIntersection(Line l1,Line l2)
{
	Vector u=l1.p-l2.p;
	double t=Cross(l2.v,u)/Cross(l1.v,l2.v);
	return l1.p+l1.v*t;
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("INTERSECTING LINES OUTPUT\n");
	while(n--)
	{
		Point p1,p2,p3,p4,q;
		p1.read(),p2.read();
		p3.read(),p4.read();
		Line l1(p1,p2-p1),l2(p3,p4-p3);
		int flag=IsLineIntersection(l1,l2);
		if(flag==1)
		{
			q=LineIntersection(l1,l2);
			printf("POINT %.2lf %.2lf\n",q.x,q.y);
		}
		else printf(flag?"LINE\n":"NONE\n");
	}
	printf("END OF OUTPUT\n");
}
