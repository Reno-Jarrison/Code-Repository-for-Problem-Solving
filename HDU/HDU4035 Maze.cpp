#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
using namespace std;
const int maxn=1e4+5;
const double eps=1e-9;
double p[maxn][2],dp[maxn][3];
vector<int>e[maxn];
void dfs(int u,int f)
{
    int len=e[u].size();
    double tmp=0.0,q=1.0-p[u][0]-p[u][1],r=q/len;
    for(int i=0;i<len;i++)
    {
        int v=e[u][i];
        if(v==f) continue;
        dfs(v,u);
        tmp+=dp[v][1];
        dp[u][0]+=dp[v][0];
        dp[u][2]+=dp[v][2];
    }
    tmp=1.0-tmp*r;
    dp[u][0]=(dp[u][0]*r+p[u][0])/tmp;
    dp[u][1]=r/tmp;
    dp[u][2]=(dp[u][2]*r+q)/tmp;
}
int main()
{
    int t,n,u,v,cases=0;
    double p1,p2;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++) e[i].clear();
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&u,&v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for(int i=1;i<=n;i++)
            scanf("%lf%lf",&p1,&p2),p[i][0]=p1/100.0,p[i][1]=p2/100.0;
        dfs(1,0),printf("Case %d: ",++cases);
        if(fabs(dp[1][0]-1.0)<eps) puts("impossible");
        else printf("%.6lf\n",dp[1][2]/(1-dp[1][0]));
    }
}