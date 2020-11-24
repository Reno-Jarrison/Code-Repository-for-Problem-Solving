#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct Point
{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
	void read()
	{	scanf("%lf%lf",&x,&y); }
}p1[105],p2[105];
typedef Point Vector;
const double eps=1e-10;
int dcmp(double x)
{	return fabs(x)<eps?0:x<0?-1:1; }
bool operator <(const Point& a,const Point& b)
{	return a.x<b.x||(a.x==b.x&&a.y<b.y); }
bool operator ==(const Point& a,const Point& b)
{	return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0; }

Vector operator +(Vector a,Vector b)
{	return Vector(a.x+b.x,a.y+b.y); }
Vector operator -(Vector a,Vector b)
{	return Vector(a.x-b.x,a.y-b.y); }
double Cross(Vector a,Vector b)
{	return a.x*b.y-a.y*b.x; }

struct Line
{
	Point p;
	Vector v;
	Line(Point a=Point(0,0),Point b=Point(0,0)):p(a),v(b-a){}
};
int LSIntersection(Line l,Point a,Point b)
{
	double c1=Cross(l.v,a-l.p),c2=Cross(l.v,b-l.p);
	if(dcmp(c1)*dcmp(c2)<0) return 1; 
	if(dcmp(c1)==0&&dcmp(c2)==0) return -1;  
	if(dcmp(c1)==0||dcmp(c2)==0) return 2;  
	return 0;
}
bool LineThroughAllSeg(Point *a,Point *b,int n,Line& L)
{
	Point *p=new Point[n<<1];
	int cnt=0;
	for(int i=0;i<n;i++)
		p[cnt++]=a[i],p[cnt++]=b[i];
	sort(p,p+cnt);
	cnt=unique(p,p+cnt)-p;
	for(int i=0;i<cnt;i++)
		for(int j=0;j<i;j++)
		{
			Line l(p[i],p[j]);
			int k;
			for(k=0;k<n;k++)
				if(!LSIntersection(l,a[k],b[k])) break;
			if(k<n) continue;
			else { L=l; delete []p; return true; }
		}
	delete []p;
	return false;
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			p1[i].read(),p2[i].read();
		Line l;
		bool flag=LineThroughAllSeg(p1,p2,n,l);
		printf(flag?"Yes!\n":"No!\n");
	}
}
