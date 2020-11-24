#include<bits/stdc++.h>
using namespace std;
struct Point
{
	double x,y;
	Point (){}
	Point (double x,double y):x(x),y(y){}
}P[2500];
typedef Point Vector;
typedef vector<Point>Polygon;

const double eps=1e-10,PI=acos(-1);
int dcmp(double x)
{	return fabs(x)<eps?0:x>0?1:-1; }

Vector operator +(Vector A,Vector B)
{	return Vector(A.x+B.x,A.y+B.y); }
Vector operator -(Vector A,Vector B)
{	return Vector(A.x-B.x,A.y-B.y); }
Vector operator *(Vector A,double p)
{	return Vector(A.x*p,A.y*p); }
Vector operator /(Vector A,double p)
{	return Vector(A.x/p,A.y/p); }
bool operator <(const Point& A,const Point& B)
{	return A.x<B.x||(A.x==B.x&&A.y<B.y); } 
bool operator ==(const Point& A,const Point& B)
{	return dcmp(A.x-B.x)==0&&dcmp(A.y-B.y)==0; } 
double Cross(Vector A,Vector B)
{	return A.x*B.y-A.y*B.x; } 
Vector Rotate(Vector A,double ang)
{	return Vector(A.x*cos(ang)-A.y*sin(ang),A.x*sin(ang)+A.y*cos(ang)); }

double PolygonArea(Polygon poly)
{
	int n=poly.size();
	double area=0;
	for(int i=1;i<n-1;i++)
		area+=Cross(poly[i]-poly[0],poly[i+1]-poly[0]);
	return area/2;
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

int main()
{
	int t,n;
	double x,y,w,h,ang,area1,area2;
	scanf("%d",&t);
	while(t--)
	{
		int cnt=0;
		area1=area2=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{ 
			scanf("%lf%lf%lf%lf%lf",&x,&y,&w,&h,&ang);
			area1+=w*h;
			ang=ang/180*PI;
			Point p(x,y);
			w/=2,h/=2;
			for(int j=-1;j<=1;j+=2)
				for(int k=-1;k<=1;k+=2)
					P[cnt++]=p+Rotate(Vector(j*w,k*h),-ang);
		} 
		Polygon poly;
		Andrew(P,n<<2,poly);
		area2=PolygonArea(poly);
		printf("%.1lf %%\n",area1/area2*100);
	}
}
