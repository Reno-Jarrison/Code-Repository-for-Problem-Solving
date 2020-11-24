#include<cstdio>
#include<vector>
#include<cmath>
#include<iostream> 
using namespace std;
struct Point
{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
	void read()
	{	scanf("%lf%lf",&x,&y); }
};
typedef Point Vector;
typedef vector<Point> Polygon;
const double eps=1e-10;
int dcmp(double x)
{	return fabs(x)<eps?0:x<0?-1:1; }
bool operator ==(const Point& a,const Point& b)
{	return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0; }
Vector operator -(Vector a,Vector b)
{	return Vector(a.x-b.x,a.y-b.y); }
Vector operator +(Vector a,Vector b)
{	return Vector(a.x+b.x,a.y+b.y); }
double Dot(Vector a,Vector b)
{	return a.x*b.x+a.y*b.y; }
double Cross(Vector a,Vector b)
{	return a.x*b.y-a.y*b.x; }
bool OnSegment(Point p,Point a,Point b)
{	return dcmp(Cross(a-p,b-p))==0&&dcmp(Dot(a-p,b-p))<0; }

int PointPolygonPos(Point p,Polygon poly)
{
	int wn=0,n=poly.size();
	for(int i=0;i<n-1;i++)
		if(p==poly[i]) return 0;  //p与多边形顶点重合 
	for(int i=0;i<n;i++)
	{
		if(OnSegment(p,poly[i],poly[(i+1)%n])) return 0;
		int k=dcmp(Cross(poly[(i+1)%n]-poly[i],p-poly[i]));
        int d1=dcmp(poly[i].y-p.y);
        int d2=dcmp(poly[(i+1)%n].y-p.y);
        if(k>0&&d1<=0&&d2>0) wn++;
        if(k<0&&d2<=0&&d1>0) wn--;
    }
	return wn?-1:1; 
}
bool SSIntersection(Point a1,Point a2,Point b1,Point b2)
{   
	double c1=Cross(a2-a1,b1-a1),c2=Cross(a2-a1,b2-a1);
	double c3=Cross(b2-b1,a1-b1),c4=Cross(b2-b1,a2-b1);
	return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0; 
}
int SegPolyPos(Point a,Point b,Polygon poly)
{
	int n=poly.size();
	if(a==b)
	{
		for(int i=0;i<n-1;i++)
			if(OnSegment(a,poly[i],poly[i+1])) return 0;
		return PointPolygonPos(a,poly);
	}
	for(int i=0;i<n-1;i++)
	{
		if(OnSegment(poly[i],a,b)) return 0;
		if(OnSegment(a,poly[i],poly[i+1])) return 0;
		if(OnSegment(b,poly[i],poly[i+1])) return 0;
		if(a==poly[i]||b==poly[i]) return 0;
		if(SSIntersection(a,b,poly[i],poly[i+1])) return 0;
	}
	return PointPolygonPos(a,poly);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		Point a,b;
		a.read(),b.read();
		double x1,x2,y1,y2;
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		Polygon poly;
		poly.push_back(Point(x1,y1));
		poly.push_back(Point(x1,y2));
		poly.push_back(Point(x2,y2));
		poly.push_back(Point(x2,y1));
		poly.push_back(Point(x1,y1));
		printf(SegPolyPos(a,b,poly)>0?"F\n":"T\n");
	}
}
