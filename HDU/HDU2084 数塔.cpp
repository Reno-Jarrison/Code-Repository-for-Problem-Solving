#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int a[maxn][maxn],dp[maxn][maxn];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=i;j++)
                cin>>a[i][j];
        memset(dp,0,sizeof(dp));
        for(int i=n;i;i--)
            for(int j=1;j<=i;j++)
                dp[i][j]=max(dp[i+1][j],dp[i+1][j+1])+a[i][j];
        printf("%d\n",dp[1][1]);    
    }
}