#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
double dp[maxn][maxn];
void init(int n)
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dp[i][j]=0.5*(dp[i-1][j]+dp[i][j-1])+1;
}
int main()
{
    init(1000);
    int t,n;
    scanf("%d",&t);
    while(t--)
        scanf("%d",&n),printf("%.2lf\n",dp[n][n]);
}