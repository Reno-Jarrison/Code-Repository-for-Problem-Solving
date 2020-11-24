#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+5;
struct Point
{
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
}p[maxn];
typedef Point Vector;
Vector operator -(const Vector& a,const Vector& b)
{   return Vector(a.x-b.x,a.y-b.y); }
bool operator <(const Point& a,const Point& b)
{   return a.x<b.x||(a.x==b.x&&a.y<b.y); }
double Cross(Vector a,Vector b)
{   return a.x*b.y-a.y*b.x; }
typedef vector<Point> Polygon; 
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
double RotatingClampShell(Polygon poly)
{
    int n=poly.size()-1;
    double ans=0;
    for(int i=0;i<n;i++)
    {
        int pt=1;
        for(int j=i+1;j<n;j++)
        {
            while(fabs(Cross(poly[i]-poly[pt],poly[j]-poly[pt]))
            <fabs(Cross(poly[i]-poly[pt+1],poly[j]-poly[pt+1])))
                pt=(pt+1)%n;
            ans=max(ans,0.5*fabs(Cross(poly[i]-poly[pt],poly[j]-poly[pt])));
        }
    }
    return ans;
}
int main()
{
    int n;
    while(scanf("%d",&n)&&n!=-1)
    {
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        Polygon poly;
        Andrew(p,n,poly);
        double ans=RotatingClampShell(poly);
        printf("%.2lf\n",ans);
    }
}