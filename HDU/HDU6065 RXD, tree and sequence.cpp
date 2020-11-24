#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=3e5+5;
vector<int>e[maxn];
int p[maxn],dep[maxn],fat[maxn][20],lg2[maxn]={-1};
void getlg2(int n)
{    for(int i=1;i<=n;i++) lg2[i]=lg2[i>>1]+1; }
void link(int u,int v)
{    e[u].push_back(v),e[v].push_back(u); }
void dfs(int u,int f)
{
    dep[u]=dep[f]+1,fat[u][0]=f;
    for(int i=1;(1<<i)<=dep[u];i++)
        fat[u][i]=fat[fat[u][i-1]][i-1];
    for(int v:e[u])
        if(v!=f) dfs(v,u);
}
int getlca(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    while(dep[x]>dep[y])
        x=fat[x][lg2[dep[x]-dep[y]]];
    if(x==y) return x;
    for(int i=lg2[dep[x]];~i;i--)
        if(fat[x][i]!=fat[y][i])
            x=fat[x][i],y=fat[y][i];
    return fat[x][0];
}
int lca[maxn],dp[3][maxn];
int main()
{
    getlg2(maxn-5);
    int n,k,u,v;
    while(~scanf("%d%d",&n,&k))
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&p[i]),e[i].clear();
        for(int i=1;i<n;i++)
            scanf("%d%d",&u,&v),link(u,v);
        dfs(1,0);
        for(int i=2;i<=n;i++)
            lca[i]=getlca(p[i],p[i-1]);
        memset(dp,0x3f,sizeof(dp));
        dp[0][0]=dp[1][0]=dp[2][0]=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=min(i,k);j++)
            {
                int& val=dp[i%3][j];
                val=min(dp[(i-1)%3][j],dp[(i-1)%3][j-1]+dep[p[i]]);
                if(i>1) val=min(val,dp[(i-2)%3][j-1]+dep[lca[i]]);
            }
        printf("%d\n",dp[n%3][k]);
    }
}