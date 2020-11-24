#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
const int maxn=105;
int c[maxn],w[maxn],dp[maxn][maxn];
vector<int>e[maxn];
void link(int u,int v)
{    e[u].push_back(v),e[v].push_back(u); }
void dfs(int u,int f,int m)
{
    int cost=c[u]/20+(c[u]%20>0);
    for(int i=cost;i<=m;i++) dp[u][i]=w[u];
    for(int v:e[u]) if(v!=f)
    {
        dfs(v,u,m);
        for(int i=m;i;i--)
            for(int j=1;j<=i-cost;j++)
                dp[u][i]=max(dp[u][i],dp[u][i-j]+dp[v][j]);
    }
}
int main()
{
    int n,m,u,v;
    while(cin>>n>>m&&n>0)
    {
        for(int i=1;i<=n;i++)
            cin>>c[i]>>w[i],e[i].clear();
        for(int i=1;i<n;i++)
            cin>>u>>v,link(u,v);
        memset(dp,0,sizeof(dp));
        dfs(1,0,m);
        cout<<(m?dp[1][m]:0)<<endl;
    }
}