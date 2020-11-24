#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
const double PI=acos(-1);
struct Point
{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
}p[maxn];
typedef Point Vector;
typedef vector<Point> Polygon;
bool operator <(const Point& a,const Point& b)
{   return a.x<b.x||(a.x==b.x&&a.y<b.y); }
Vector operator -(Vector a,Vector b)
{   return Vector(a.x-b.x,a.y-b.y); }
double Cross(Vector a,Vector b)
{   return a.x*b.y-a.y*b.x; }
double Dot(Vector a,Vector b)
{   return a.x*b.x+a.y*b.y; }
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
    for(int i=n-2;~i;i--)
    {
        while(cnt>k&&Cross(poly[cnt-1]-poly[cnt-2],p[i]-poly[cnt-1])<=0)
            poly.pop_back(),cnt--;
        poly.push_back(p[i]),cnt++;
    }
    return n>1?cnt-1:cnt;
}
int main()
{
    int t,n,d,fst=1;
    scanf("%d",&t);
    while(t--)
    {
        if(fst) fst=0;
        else puts("");
        scanf("%d%d",&n,&d);
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        Polygon poly;
        int siz=Andrew(p,n,poly);
        double ans=2*PI*d;
        for(int i=0;i<siz;i++)
            ans+=Length(poly[i],poly[i+1]);
        printf("%.0lf\n",ans);
    }
}