#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=305;
struct node
{
    int x,y;
    node(int x=0,int y=0):x(x),y(y){}
}p[maxn<<1];
bool operator ==(const node& a,const node& b)
{    return 1LL*a.x*b.y==1LL*b.x*a.y; }
bool operator <(const node& a,const node& b)
{    return 1LL*a.x*b.y<1LL*b.x*a.y; }
int tot,h[maxn],xl[maxn],xr[maxn],w[maxn];
ll dp[maxn<<1][maxn<<1];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n),tot=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d%d",&h[i],&xl[i],&xr[i],&w[i]);
            p[++tot]=node(xl[i],h[i]);
            p[++tot]=node(xr[i],h[i]);
        }
        sort(p+1,p+tot+1);
        tot=unique(p+1,p+tot+1)-p-1;
        for(int i=1;i<=n;i++)
        {
            xl[i]=lower_bound(p+1,p+tot+1,node(xl[i],h[i]))-p;
            xr[i]=lower_bound(p+1,p+tot+1,node(xr[i],h[i]))-p;
        }
        for(int i=1;i<=tot;i++)
            for(int l=1,r=l+i-1;r<=tot;l++,r++)
            {
                dp[l][r]=1LL<<60;
                int mxv=-1,id;
                for(int j=1;j<=n;j++)
                    if(l<=xl[j]&&xr[j]<=r&&w[j]>mxv)
                        mxv=w[j],id=j;
                if(mxv==-1) dp[l][r]=0;
                else for(int j=xl[id];j<=xr[id];j++)
                    dp[l][r]=min(dp[l][r],dp[l][j-1]+dp[j+1][r]+mxv);
            }
        printf("%lld\n",dp[1][tot]);
    }
}