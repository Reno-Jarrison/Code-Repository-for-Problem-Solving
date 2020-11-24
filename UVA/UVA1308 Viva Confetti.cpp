#include<bits/stdc++.h>
using namespace std;
struct Point
{
	double x,y;
	Point(){}
	Point(double x,double y):x(x),y(y){}
};
typedef Point Vector;
struct Circle
{
	Point o; 
	double r;
	Circle(){}
	Circle(Point o,double r):o(o),r(r){}
	Point point(double rad)
	{	return Point(o.x+cos(rad)*r,o.y+sin(rad)*r); }
}C[105];

Vector operator +(Vector A,Vector B)
{	return Vector(A.x+B.x,A.y+B.y); }
Vector operator -(Vector A,Vector B)
{	return Vector(A.x-B.x,A.y-B.y); }
Vector operator *(Vector A,double p)
{	return Vector(A.x*p,A.y*p); }
Vector operator /(Vector A,double p)
{	return Vector(A.x/p,A.y/p); }

double Dot(Vector A,Vector B)
{	return A.x*B.x+A.y*B.y; }
double Length(Vector A)
{	return sqrt(Dot(A,A)); }
double Cross(Vector A,Vector B)
{	return A.x*B.y-A.y*B.x; } 
double Angle(Vector A)
{	return atan2(A.y,A.x); }
double Angle(Vector A,Vector B)
{	return acos(Dot(A,B)/Length(A)/Length(B)); } 
const double eps=5e-13;
const double PI=acos(-1.0);
int dcmp(double x)
{	return fabs(x)<eps?0:x>0?1:-1; } 
bool operator <(const Point& A,const Point& B)
{	return A.x<B.x||(A.x==B.x&&A.y<B.y); }
bool operator ==(const Point& A,const Point& B)
{	return dcmp(A.x-B.x)==0&&dcmp(A.y-B.y)==0; }

double modi(double x)
{
	double PI2=PI*2;
	while(dcmp(x-PI2)>0) x-=PI2;
	while(dcmp(x)<0) x+=PI2;
	return x;
}
int CCIntersection(Circle C1,Circle C2,vector<double>& v)
{
	double d=Length(C1.o-C2.o);
	if(dcmp(d)==0) return dcmp(C1.r-C2.r)==0?-1:0;
	if(dcmp(C1.r+C2.r-d)<0) return 0;
	if(dcmp(fabs(C1.r-C2.r)-d)>0) return 0;
	double a=Angle(C2.o-C1.o);
	double b=acos((C1.r*C1.r+d*d-C2.r*C2.r)/(2*C1.r*d));
	v.push_back(modi(a-b)),v.push_back(modi(a+b));
	return 2;
}
Point q(Point P,double r,double ang)
{
	return Point(P.x+r*cos(ang),P.y+r*sin(ang));
}
int PointCirclePos(Point P,Circle C)
{	return dcmp(Length(P-C.o)-C.r); } 
int n,vis[105]; 
void judge(Point p)
{
	for(int i=n-1;i>=0;i--)
		if(PointCirclePos(p,C[i])<=0)
			{	vis[i]=true; return; } 
}
int main()
{
	while(~scanf("%d",&n)&&n)
	{
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++)
			scanf("%lf%lf%lf",&C[i].o.x,&C[i].o.y,&C[i].r);
		for(int i=0;i<n;i++)
		{
			vector<double>ang;
			ang.push_back(0); 
			ang.push_back(PI*2); 
			for(int j=0;j<n;j++)
				if(j!=i) CCIntersection(C[i],C[j],ang);
			sort(ang.begin(),ang.end());
			unique(ang.begin(),ang.end());
			int len=ang.size();
			for(int j=1;j<len;j++)
			{
				double midang=(ang[j-1]+ang[j])/2,r;
				r=C[i].r+eps; 
				judge(q(C[i].o,r,midang));
				r=C[i].r-eps; 
				judge(q(C[i].o,r,midang));
			}
			judge(C[i].o);
		}
		int ans=0;
		for(int i=0;i<n;i++) ans+=vis[i];
		printf("%d\n",ans);
	}
}