#include<cstdio>
#include<vector>
using namespace std;
const int maxn=1e4+5;
struct edge
{
    int to,w;
    edge(int to,int w):to(to),w(w){}
};
vector<edge>e[maxn];
void link(int u,int v,int w)
{   e[u].push_back(edge(v,w)),e[v].push_back(edge(u,w)); }
int dp[maxn],ans;
void dfs(int u,int f)
{
    for(int i=0;i<(int)e[u].size();i++)
    {
        int v=e[u][i].to,w=e[u][i].w;
        if(v==f) continue;
        dfs(v,u);
        ans=max(ans,dp[u]+dp[v]+w);
        dp[u]=max(dp[u],dp[v]+w);
    }
}
int main()
{
    int u,v,w;
    while(~scanf("%d%d%d",&u,&v,&w))
        link(u,v,w);
    dfs(1,0),printf("%d",ans);
}