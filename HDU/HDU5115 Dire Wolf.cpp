#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=205,inf=0x7fffffff;
int a[maxn],b[maxn],dp[maxn][maxn];
int main()
{
    int t,n,ks=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        b[n+1]=0;
        for(int i=1;i<=n;i++)
            dp[i][i]=a[i]+b[i-1]+b[i+1];
        for(int i=2;i<=n;i++)
            for(int l=1,r=l+i-1;r<=n;l++,r++)
            {
                dp[l][r]=inf;
                for(int j=l;j<=r;j++)
                {
                    int cost=a[j]+b[l-1]+b[r+1];
                    dp[l][r]=min(dp[l][r],dp[l][j-1]+dp[j+1][r]+cost);
                }
            }
        printf("Case #%d: %d\n",++ks,dp[1][n]);
    }
}