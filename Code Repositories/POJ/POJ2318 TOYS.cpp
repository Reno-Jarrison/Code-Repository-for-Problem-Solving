#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=5e3+5;
int cnt[maxn];
struct Point
{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y) {}
}p1[maxn],p2[maxn];
typedef Point Vector;
const double eps=1e-10;
Vector operator -(Vector a,Vector b)
{	return Vector(a.x-b.x,a.y-b.y); }
double Cross(Vector a,Vector b)
{	return a.x*b.y-a.y*b.x; }

int main()
{
	int n,m;
	double x1,y1,x2,y2,u,l,x,y;
	while(~scanf("%d",&n)&&n)
	{
		memset(cnt,0,sizeof(cnt));
		scanf("%d%lf%lf%lf%lf",&m,&x1,&y1,&x2,&y2);
		p1[n]=Point(x2,y1),p2[n]=Point(x2,y2);
		for(int i=0;i<n;i++)
		{
			scanf("%lf%lf",&u,&l);
			p1[i]=Point(u,y1),p2[i]=Point(l,y2);
		}
		for(int i=0;i<m;i++)
		{
			scanf("%lf%lf",&x,&y);
			Point p(x,y); 
			int pt=0;
			while(Cross(p1[pt]-p2[pt],p-p1[pt])<0) pt++;
			cnt[pt]++;
		}
		for(int i=0;i<=n;i++)
			printf("%d: %d\n",i,cnt[i]);
		printf("\n");
	}
}
