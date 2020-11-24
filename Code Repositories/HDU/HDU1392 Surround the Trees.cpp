#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
struct Point
{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
}p[maxn];
typedef Point Vector;
typedef vector<Point> Polygon;
bool operator <(const Point& a,const Point& b)
{   return a.x<b.x||(a.x==b.x&&a.y<b.y); }
Vector operator -(const Vector a,const Vector b)
{   return Vector(a.x-b.x,a.y-b.y); }
double Cross(Vector a,Vector b)
{   return a.x*b.y-a.y*b.x; }
double Dot(Vector a,Vector b)
{   return a.x*b.x+a.y*b.y; }
double Cross(Point o,Point a,Point b)
{   return Cross(a-o,b-o); }
double Length(Point a,Point b)
{   return sqrt(Dot(a-b,a-b)); }
int Andrew(Point *p,int n,Polygon& poly)
{
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
int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        if(n<=1) puts("0.00");
        else
        {
            double ans=0;
            Polygon poly;
            int siz=Andrew(p,n,poly);
            if(siz==2) ans=Length(poly[0],poly[1]);
            else for(int i=0;i<siz;i++)
                ans+=Length(poly[i],poly[i+1]);
            printf("%.2lf\n",ans);
        }
    }
}
