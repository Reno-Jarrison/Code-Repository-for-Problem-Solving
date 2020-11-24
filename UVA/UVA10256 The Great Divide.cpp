#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
struct Point
{
	double x,y;
	Point(){}
	Point(double x,double y):x(x),y(y){}
}P1[maxn],P2[maxn];
typedef Point Vector;
typedef vector<Point> Polygon;

const double eps=1e-10;
int dcmp(double x)
{	return fabs(x)<eps?0:x<0?-1:1; }
bool operator <(const Point& A,const Point& B)
{	return A.x<B.x||(A.x==B.x&&A.y<B.y); }
bool operator ==(const Point& A,const Point& B)
{	return dcmp(A.x-B.x)==0&&dcmp(A.y-B.y)==0; } 

Vector operator +(Vector A,Vector B) { return Vector(A.x+B.x,A.y+B.y); } 
Vector operator -(Vector A,Vector B) { return Vector(A.x-B.x,A.y-B.y); } 
Vector operator *(Vector A,double p) { return Vector(A.x*p,A.y*p); } 
Vector operator /(Vector A,double p) { return Vector(A.x/p,A.y/p); } 
double Cross(Vector A,Vector B) { return A.x*B.y-A.y*B.x; }
double Dot(Vector A,Vector B) { return A.x*B.x+A.y*B.y; }

bool SegIntersection(Point A1,Point A2,Point B1,Point B2)
{
	double c1=Cross(A2-A1,B1-A1),c2=Cross(A2-A1,B2-A1);
	double c3=Cross(B2-B1,A1-B1),c4=Cross(B2-B1,A2-B1);
	return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0; 
} 
bool OnSegment(Point P,Point A,Point B)
{	return dcmp(Cross(A-P,B-P))==0&&dcmp(Dot(A-P,B-P))<0; }

int PointPolygonPos(Point P,Polygon poly)
{
	int wn=0,n=poly.size();
	for(int i=0;i<n;i++)
	{
		if(OnSegment(P,poly[i],poly[(i+1)%n])) return 0;
		int k=dcmp(Cross(poly[(i+1)%n]-poly[i],P-poly[i]));
		int d1=dcmp(poly[i].y-P.y);
		int d2=dcmp(poly[(i+1)%n].y-P.y);
		if(k>0&&d1<=0&&d2>0) wn++;
		if(k<0&&d2<=0&&d1>0) wn--;
	}
	return wn?-1:1;
}
int Andrew(Point *p,int n,Polygon& poly)
{
	poly.clear();
	sort(p,p+n);
	int cnt=0;
	for(int i=0;i<n;i++)
	{
		while(cnt>1&&Cross(poly[cnt-1]-poly[cnt-2],p[i]-poly[cnt-1])<=0)
			poly.pop_back(),cnt--;
		poly.push_back(p[i]),cnt++;
	}
	int k=cnt;
	for(int i=n-2;i>=0;i--)
	{
		while(cnt>k&&Cross(poly[cnt-1]-poly[cnt-2],p[i]-poly[cnt-1])<=0)
			poly.pop_back(),cnt--;
		poly.push_back(p[i]),cnt++;
	}
	return n>1?cnt-1:cnt;
} 
bool PPIntersection(Polygon poly1,Polygon poly2)
{
	int n1=poly1.size(),n2=poly2.size();
	if(n2>3) for(int i=0;i<n1;i++)
		if(PointPolygonPos(poly1[i],poly2)<=0)
			return true;
	if(n1>3) for(int i=0;i<n2;i++)
		if(PointPolygonPos(poly2[i],poly1)<=0)
			return true;
	if(n1>1&&n2>1)
	{
		for(int i=0;i<n1;i++)
		for(int j=0;j<n2;j++)
			if(SegIntersection(poly1[i],poly1[i+1],poly2[j],poly2[j+1]))
				return true;
	}
	else if(n1>1) return OnSegment(poly2[0],poly1[0],poly1[1]);
	else if(n2>1) return OnSegment(poly1[0],poly2[0],poly2[1]);
	else return poly1[0]==poly2[1];
	return false;
} 
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m)&&n&&m)
	{
		for(int i=0;i<n;i++) scanf("%lf%lf",&P1[i].x,&P1[i].y);		
		for(int i=0;i<m;i++) scanf("%lf%lf",&P2[i].x,&P2[i].y);		
		Polygon poly1,poly2;
		Andrew(P1,n,poly1);
		Andrew(P2,m,poly2);
		printf(!PPIntersection(poly1,poly2)?"Yes\n":"No\n");
	} 
}
