#include<bits/stdc++.h>
using namespace std;
struct Point
{
	double x,y;
	Point(){}
	Point(double x,double y):x(x),y(y){}
}P[10005];
typedef Point Vector;

const double eps=1e-10;
typedef vector<Point> Polygon;
Vector operator +(Vector A,Vector B){ return Vector(A.x+B.x,A.y+B.y); }
Vector operator -(Vector A,Vector B){ return Vector(A.x-B.x,A.y-B.y); }
double Cross(Vector A,Vector B) { return A.x*B.y-A.y*B.x; }
int dcmp(double x)
{	return fabs(x)<eps?0:x<0?-1:1; }
bool operator <(const Point& A,const Point& B)
{	return A.x<B.x||(A.x==B.x&&A.y<B.y); }
bool operator ==(const Point& A,const Point& B)
{	return dcmp(A.x-B.x)==0&&dcmp(A.y-B.y)==0; }

double dist(Point p1,Point p2,double xt,double yt)
{
	if(p1.x!=p2.x)
	{
		double A=(p1.y-p2.y)/(p1.x-p2.x),B=-1,C=p1.y-A*p1.x;
		return fabs(A*xt+B*yt+C)/sqrt(A*A+B*B);
	}
	else return fabs(p1.x-xt);
}
double Andrew(Point *p,int n,double xt,double yt)
{
	Polygon poly;
	sort(p,p+n);
	int cnt=0;
	double ans=1e12;
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
	for(int i=0;i<cnt-1;i++)
		ans=min(ans,dist(poly[i+1],poly[i],xt,yt));
	return ans;
}

int main()
{
	int t,n,cases=0;
	scanf("%d",&t);
	while(t--)
	{
		double xt=0,yt=0,ans=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&P[i].x,&P[i].y);
			xt+=P[i].x,yt+=P[i].y;
		}
		if(n>2)	ans=Andrew(P,n,xt/n,yt/n);
		printf("Case #%d: %.3lf\n",++cases,ans);
	}
}
