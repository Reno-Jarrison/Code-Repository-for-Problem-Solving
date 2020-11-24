#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+5;
struct Point 
{
	double x,y;
	Point(){}
	Point(double x,double y):x(x),y(y){}
}p[maxn];
typedef Point Vector;
typedef vector<Point> Polygon;

const double eps=1e-10;
int dcmp(double x)
{	return fabs(x)<eps?0:x<0?-1:1; }
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
double Dot(Vector A,Vector B)
{	return A.x*B.x+A.y*B.y; }
double Length(Vector A)
{	return sqrt(Dot(A,A)); }

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
inline double sqr(double x) {	return x*x; }
//旋转卡壳求最远点对（返回点对距离） 
double RotatingClampShell(Polygon poly)
{
	int n=poly.size(),pt=2;
	if(n==3) return Length(poly[0]-poly[1]); 
	double ans=0;
	for(int i=0;i<n-1;i++)
	{
		while(fabs(Cross(poly[i]-poly[pt],poly[i+1]-poly[pt]))
		<fabs(Cross(poly[i]-poly[pt+1],poly[i+1]-poly[pt+1])))
			pt=(pt+1)%(n-1);
		ans=max(ans,Length(poly[i]-poly[pt])); 
		ans=max(ans,Length(poly[i+1]-poly[pt])); 
	}
	return ans;
}
int main()
{
	int t,n;
	Polygon poly;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(p,0,sizeof(p));
		for(int i=0;i<(n<<2);i+=4)
		{
			double x,y,w;
			scanf("%lf%lf%lf",&x,&y,&w);
			p[i]=Point(x,y);
			p[i+1]=Point(x+w,y);
			p[i+2]=Point(x,y+w);
			p[i+3]=Point(x+w,y+w);
		}
		Andrew(p,n<<2,poly);
		printf("%.0lf\n",sqr(RotatingClampShell(poly)));
	}
}
