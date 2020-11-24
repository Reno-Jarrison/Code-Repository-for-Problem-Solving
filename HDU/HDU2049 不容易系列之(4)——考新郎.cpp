#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=25;
ll dp[maxn]={0,0,1},c[maxn][maxn];
int main()
{
    for(int i=3;i<maxn;i++)
        dp[i]=(i-1)*(dp[i-1]+dp[i-2]);
    for(int i=1;i<maxn;i++)
    {
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;j++)
            c[i][j]=c[i-1][j-1]+c[i-1][j];
    }
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        printf("%lld\n",dp[m]*c[n][m]);
    }
}