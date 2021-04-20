#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct Point
{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
}p[55];
typedef Point Vector;
Vector operator -(Vector a,Vector b)
{	return Vector(a.x-b.x,a.y-b.y); }
double area(Vector v1,Vector v2)
{	return v1.x*v2.y-v1.y*v2.x; }
int main()
{
	int n,m;
	scanf("%d",&n);
	double ans=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m);
		for(int j=0;j<m;j++)
			scanf("%lf%lf",&p[j].x,&p[j].y);
		p[m]=p[0];
		double sum=0;
		for(int j=0;j<m;j++)
			sum+=area(p[j]-p[0],p[j+1]-p[0]);
		ans+=fabs(sum);
	}
	printf("%lld",(ll)(ans/2));
}