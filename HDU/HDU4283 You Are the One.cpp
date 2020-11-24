#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=105,inf=0x7fffffff;
int a[maxn],s[maxn],dp[maxn][maxn];
int sum(int l,int r)
{    return l<=r?s[r]-s[l-1]:0; }
int main()
{
    int t,n,ks=0;
    scanf("%d",&t);    
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]),s[i]=s[i-1]+a[i];
        for(int i=2;i<=n;i++)
            for(int l=1,r=l+i-1;r<=n;l++,r++)
            {
                dp[l][r]=inf;
                for(int j=1;j<=i;j++)
                {
                    int val=a[l]*(j-1)+dp[l+1][l+j-1]+dp[l+j][r]+sum(l+j,r)*j;
                    dp[l][r]=min(dp[l][r],val);
                }
            }
        printf("Case #%d: %d\n",++ks,dp[1][n]);
    }
}