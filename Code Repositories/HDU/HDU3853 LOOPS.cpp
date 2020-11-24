#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn=1e3+5;
const double eps=1e-6;
double p[maxn][maxn][3],dp[maxn][maxn];
int main()
{
    int r,c;
    while(~scanf("%d%d",&r,&c))
    {
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=r;i++)
            for(int j=1;j<=c;j++)
                for(int k=0;k<3;k++)
                    scanf("%lf",&p[i][j][k]);
        for(int i=r;i;i--)
            for(int j=c;j;j--)
            {
                if(i==r&&j==c) continue;
                if(fabs(p[i][j][0]-1.0)<eps) continue;
                double sum=p[i][j][1]*dp[i][j+1]+p[i][j][2]*dp[i+1][j]+2.0;
                dp[i][j]=sum/(1-p[i][j][0]);
            }
        printf("%.3lf\n",dp[1][1]);
    }
}