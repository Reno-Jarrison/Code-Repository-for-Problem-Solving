#include<cstdio>
#include<algorithm>
#include<cmath>
#define inf 0x7fffffff
using namespace std;
double d(int x,int y)
{    return sqrt(1LL*x*x+1LL*y*y); }
int main()
{
    int n,x,y,x1=inf,x2=-inf,y1=inf,y2=-inf;
    bool xtag=false,ytag=false;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&x,&y);
        if(x) xtag=true,x1=min(x1,x),x2=max(x2,x);
        if(y) ytag=true,y1=min(y1,y),y2=max(y2,y);
    }
    double ans=0;
    if(xtag) ans=max(ans,(double)x2-x1);
    if(ytag) ans=max(ans,(double)y2-y1);
    if(xtag&&ytag) 
    {
        ans=max(ans,max(d(x1,y1),d(x1,y2)));
        ans=max(ans,max(d(x2,y1),d(x2,y2)));
    }
    printf("%.6lf",ans);
}