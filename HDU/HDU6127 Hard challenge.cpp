#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e4+5;
const double PI=acos(-1);
struct Point
{
    double x,y;
    ll s;
    Point(double x=0,double y=0):x(x),y(y){}
}p[maxn<<1];
typedef Point Vector;
double Angle(Vector a)
{   return atan2(a.y,a.x); }
bool operator <(const Point& a,const Point& b)
{   return Angle(a)<Angle(b); }
bool check(int a,int b,int n)
{   return Angle(p[b])+(b>n?2*PI:0)-Angle(p[a])<PI; }
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%lf%lf%lld",&p[i].x,&p[i].y,&p[i].s);
        sort(p+1,p+n+1);
        for(int i=1;i<=n;i++) 
            p[i].s+=p[i-1].s,p[n+i]=p[i];
        for(int i=1;i<=n;i++) 
            p[n+i].s=p[i].s+p[n].s;
        ll ans=0;
        for(int i=1,pt=1;i<=n;i++)
        {
            while(pt<2*n&&check(i,pt+1,n)) pt++;
            ll sum=p[pt].s-p[i-1].s,res=p[n].s-sum;
            ans=max(ans,sum*res);
        }
        printf("%lld\n",ans);
    }
}