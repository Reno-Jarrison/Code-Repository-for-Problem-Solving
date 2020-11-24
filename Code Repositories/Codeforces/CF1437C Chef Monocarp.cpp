#include<bits/stdc++.h>
using namespace std;
const int maxn=205;
int a[maxn],dp[maxn][maxn*2];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        memset(dp,0x3f,sizeof(dp));
        memset(dp[0],0,sizeof(dp[0]));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n*2;j++)
                dp[i][j]=min(dp[i][j-1],dp[i-1][j-1]+abs(a[i]-j));
        printf("%d\n",dp[n][n*2]);
    }
}