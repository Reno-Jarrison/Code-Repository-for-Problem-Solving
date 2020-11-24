#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e5+5,inf=0x3f3f3f3f;
int dp[maxn];
int main()
{
    int t,n,x,ks=0;
    scanf("%d",&t);
    while(t--)
    {
        int l=1,r=1,mxv=-inf,las=1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            if(dp[i-1]<0) las=i;
            dp[i]=max(dp[i-1],0)+x;
            if(dp[i]>mxv) l=las,r=i,mxv=dp[i];            
        }
        if(ks) puts("");
        printf("Case %d:\n%d %d %d\n",++ks,mxv,l,r);
    }
}