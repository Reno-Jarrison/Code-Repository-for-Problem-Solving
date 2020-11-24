#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e5+10;
double dp[maxn];
int to[maxn];
int main()
{
    int n,m,u,v;
    while(~scanf("%d%d",&n,&m)&&n)
    {
        memset(to,-1,sizeof(to));
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=m;i++)
            scanf("%d%d",&u,&v),to[u]=v;
        for(int i=n-1;i>=0;i--)
        {
            if(to[i]!=-1) dp[i]=dp[to[i]];
            else 
            {
                double tmp=0.0;
                for(int j=1;j<=6;j++)
                    tmp+=dp[i+j];
                dp[i]=tmp/6.0+1;
            }
        }
        printf("%.4lf\n",dp[0]);
    }
}