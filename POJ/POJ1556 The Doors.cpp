#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=150;
double dist[maxn],d[maxn][maxn],inf=1e3;
bool vis[maxn];
struct Point
{
	double x,y;
	Point(double x=0,double y=0):x(x),y(y){}
}p[maxn];
typedef Point Vector; 
const double eps=1e-10;
int dcmp(double x)
{	return fabs(x)<eps?0:x<0?-1:1; } 
Vector operator -(Vector a,Vector b)
{	return Vector(a.x-b.x,a.y-b.y); }
double Cross(Vector a,Vector b)
{	return a.x*b.y-a.y*b.x; } 
double Dot(Vector a,Vector b)
{	return a.x*b.x+a.y*b.y; }
double Length(Vector a)
{	return sqrt(Dot(a,a)); }
double Dist(Point a,Point b)
{	return Length(a-b); }
bool SSIntersection(Point a1,Point a2,Point b1,Point b2)
{
	double c1=Cross(a2-a1,b1-a1),c2=Cross(a2-a1,b2-a1);
	double c3=Cross(b2-b1,a1-b1),c4=Cross(b2-b1,a2-b1);
	return dcmp(c1)*dcmp(c2)<0&&dcmp(c3)*dcmp(c4)<0;
}

int main()
{
	int n;
	while(scanf("%d",&n)&&n!=-1)
	{
		int cnt=1;
		p[0]=Point(0,5);
		for(int i=0;i<n;i++)
		{
			double x,y;
			scanf("%lf",&x);
			for(int i=0;i<4;i++)
				scanf("%lf",&y),p[cnt++]=Point(x,y);
		}
		p[cnt++]=Point(10,5);
		for(int i=0;i<cnt;i++)
		{
			dist[i]=1e3;
			for(int j=0;j<cnt;j++)
				d[i][j]=1e3;
		}
		for(int i=0;i<cnt;i++)
			for(int j=i+1;j<cnt;j++)
			{
				if(dcmp(p[i].x-p[j].x)==0) continue;
				bool flag=false;
				for(int k=1;k<=n<<2&&!flag;k+=4)
				{
					Point p1(p[k].x,0),p2(p[k].x,10);
					flag|=SSIntersection(p[i],p[j],p1,p[k]);
					flag|=SSIntersection(p[i],p[j],p[k+1],p[k+2]);
					flag|=SSIntersection(p[i],p[j],p[k+3],p2);
				}
				if(flag) continue;
				else d[i][j]=d[j][i]=Dist(p[i],p[j]);
			}
		memset(vis,0,sizeof(vis));
		dist[0]=0;
		for(int i=0;i<cnt;i++)
		{
			int minm=inf,minid;
			for(int j=0;j<cnt;j++)
				if(dist[j]<minm&&!vis[j]) minm=dist[j],minid=j;
			vis[minid]=true;
			for(int j=0;j<cnt;j++)
				dist[j]=min(dist[j],dist[minid]+d[minid][j]);
		}
		printf("%.2lf\n",dist[cnt-1]);
	}
}
