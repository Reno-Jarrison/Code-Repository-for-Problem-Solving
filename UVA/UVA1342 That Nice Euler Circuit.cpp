#include<bits/stdc++.h>
using namespace std;
struct Point
{
	double x,y;
	Point(){}
	Point(double x,double y):x(x),y(y){}
}P0[305],P1[100005];
typedef Point Vector;
const double eps=1e-10;
int dcmp(double x)
{
	if(fabs(x)<eps) return 0;
	return x>0?1:-1;
}
Vector operator +(Vector A,Vector B)
{	return Vector(A.x+B.x,A.y+B.y); }
Vector operator -(Vector A,Vector B)
{	return Vector(A.x-B.x,A.y-B.y); }
Vector operator *(Vector A,double p)
{	return Vector(A.x*p,A.y*p); }
bool operator <(const Point& A,const Point& B)
{	return A.x<B.x||(A.x==B.x&&A.y<B.y); }
bool operator ==(const Point& A,const Point& B)
{	return dcmp(A.x-B.x)==0&&dcmp(A.y-B.y)==0; }
double Dot(Vector A,Vector B)
{	return A.x*B.x+A.y*B.y; }
double Cross(Vector A,Vector B)
{	return A.x*B.y-A.y*B.x; }
Point Intersec(Point P,Vector v,Point Q,Vector w)
{
	Vector u=P-Q;
	double t=Cross(w,u)/Cross(v,w);
	return P+v*t;
} 
bool SegIntersec(Point A1,Point A2,Point B1,Point B2)
{
	double c1=Cross(A2-A1,B1-A1),c2=Cross(A2-A1,B2-A1);
	double c3=Cross(B2-B1,A1-B1),c4=Cross(B2-B1,A2-B1);
	return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
}
bool OnSegment(Point P,Point A,Point B)
{	return dcmp(Cross(A-P,B-P))==0&&dcmp(Dot(A-P,B-P))<0; }
int main()
{
	int n,e,v,cases=0;
	while(scanf("%d",&n)!=EOF&&n)
	{
		memset(P0,0,sizeof(P0));
		memset(P1,0,sizeof(P1));
		for(int i=0;i<n;i++)
			scanf("%lf%lf",&P0[i].x,&P0[i].y),P1[i]=P0[i];
		e=v=--n;
		for(int i=0;i<n;i++)
			for(int j=0;j<i-1;j++)
				if(SegIntersec(P0[j],P0[j+1],P0[i],P0[i+1]))
					P1[v++]=Intersec(P0[j],P0[j+1]-P0[j],P0[i],P0[i+1]-P0[i]);
		sort(P1,P1+v);
		v=unique(P1,P1+v)-P1;
		for(int i=0;i<v;i++)
			for(int j=0;j<n;j++)
				if(OnSegment(P1[i],P0[j],P0[j+1])) e++;
		printf("Case %d: There are %d pieces.\n",++cases,e-v+2);
	}
}
