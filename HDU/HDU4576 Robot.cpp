#include<bits/stdc++.h>
using namespace std;
const int maxn=200;
double dp[2][maxn];
int main()
{
    int n,m,l,r,x,tag;
    while(scanf("%d%d%d%d",&n,&m,&l,&r)&&n)
    {
        memset(dp,0,sizeof(dp));
        dp[tag=0][0]=1;
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&x),tag=!tag;
            for(int i=0;i<n;i++)
                dp[tag][i]=0.5*(dp[!tag][(i-x+n)%n]+dp[!tag][(i+x)%n]);
        }
        double ans=0;
        for(int i=l-1;i<r;i++) 
            ans+=dp[tag][i];
        printf("%.4lf\n",ans);
    }
}