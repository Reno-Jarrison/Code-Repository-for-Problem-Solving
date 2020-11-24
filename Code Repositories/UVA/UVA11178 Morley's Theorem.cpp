#include<bits/stdc++.h>
using namespace std;
struct Point
{
	double x,y;
	Point(){}
	Point(double x,double y):x(x),y(y){}
};
typedef Point Vector;
Vector operator +(Vector A,Vector B)
{	return Point(A.x+B.x,A.y+B.y); }
Vector operator -(Vector A,Vector B)
{	return Point(A.x-B.x,A.y-B.y); }
Vector operator *(Vector A,double p)
{	return Point(A.x*p,A.y*p); }
double Dot(Vector A,Vector B)
{	return A.x*B.x+A.y*B.y; }
double Length(Vector A)
{	return sqrt(Dot(A,A)); }
double Angle(Vector A,Vector B)
{	return acos(Dot(A,B)/Length(A)/Length(B)); }
double Cross(Vector A,Vector B)
{	return A.x*B.y-A.y*B.x; }
Vector Rot(Vector A,double rad)
{	return Point(A.x*cos(rad)-A.y*sin(rad),A.x*sin(rad)+A.y*cos(rad)); }
Point Intersec(Point P,Vector v,Point Q,Vector w)
{
	Vector u=P-Q;
	double t=Cross(w,u)/Cross(v,w);
	return P+v*t;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		Point P[3],Q[3];
		double a[3];
		for(int i=0;i<3;i++)
			scanf("%lf%lf",&P[i].x,&P[i].y);
		for(int i=0;i<3;i++)
			a[i]=Angle(P[(i+1)%3]-P[i],P[(i+2)%3]-P[i]);
		for(int i=0;i<3;i++)
		{
			Point p1=P[(i+1)%3],p2=P[(i+2)%3];
			double a1=a[(i+1)%3],a2=a[(i+2)%3];
			Vector v1=Rot(p2-p1,a1/3),v2=Rot(p1-p2,-a2/3);
			Q[i]=Intersec(p1,v1,p2,v2);
			printf("%.6lf %.6lf ",Q[i].x,Q[i].y);
		}
		printf("\n");
	}
}
