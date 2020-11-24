#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
const double eps=1e-10,inf=1e10;
struct Point
{
	double x,y;
	Point(){}
	Point(double x,double y):x(x),y(y){}
}A[maxn],B[maxn];
int dcmp(double x)
{	return fabs(x)<eps?0:x>0?1:-1; }
typedef Point Vector;
Vector operator +(Vector A,Vector B)
{	return Vector(A.x+B.x,A.y+B.y); }
Vector operator -(Vector A,Vector B)
{	return Vector(A.x-B.x,A.y-B.y); }
Vector operator *(Vector A,double p)
{	return Vector(A.x*p,A.y*p); }
Vector operator /(Vector A,double p)
{	return Vector(A.x/p,A.y/p); }
bool operator ==(const Point& a,const Point& b)
{	return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0; }
double Dot(Vector A,Vector B)
{	return A.x*B.x+A.y*B.y; }
double Length(Vector A)
{	return sqrt(Dot(A,A)); } 
double Cross(Vector A,Vector B)
{	return A.x*B.y-A.y*B.x; }
double DistoSeg(Point P,Point A,Point B)
{
	if(A==B) return Length(P-A);
	Vector v1=B-A,v2=P-A,v3=P-B; 
	if(dcmp(Dot(v1,v2))<0) return Length(v2);
	if(dcmp(Dot(v1,v3))>0) return Length(v3);
	return fabs(Cross(v1,v2))/Length(v1); 
}
int main()
{
	int t,a,b,cases=0;
	scanf("%d",&t);
	while(t--)
	{
		double la=0,lb=0,maxd=-inf,mind=inf;
		scanf("%d%d",&a,&b);
		for(int i=0;i<a;i++)
		{
			scanf("%lf%lf",&A[i].x,&A[i].y);
			i?la+=Length(A[i]-A[i-1]):false;
		}
		for(int i=0;i<b;i++)
		{
			scanf("%lf%lf",&B[i].x,&B[i].y);
			i?lb+=Length(B[i]-B[i-1]):false;	 
		}
		Point Pa=A[0],Pb=B[0];
		int pta=0,ptb=0;
		while(pta<a-1&&ptb<b-1)
		{
			double da=Length(A[pta+1]-Pa);
			double db=Length(B[ptb+1]-Pb);
			double t=min(da/la,db/lb);
			Vector va=(A[pta+1]-Pa)/da*t*la;
			Vector vb=(B[ptb+1]-Pb)/db*t*lb;
			Point Pc=Pb+vb-va;
			mind=min(mind,DistoSeg(Pa,Pb,Pc));
			maxd=max(maxd,Length(Pa-Pc));
			maxd=max(maxd,Length(Pa-Pb));
			Pa=Pa+va,Pb=Pb+vb; 
			Pa==A[pta+1]?pta++:false;
			Pb==B[ptb+1]?ptb++:false;
		}
		printf("Case %d: %d\n",++cases,(int)floor(maxd-mind+0.5));
	}
}
