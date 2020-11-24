#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
const int maxn=1e4+5;
int dp[maxn][3];
struct edge
{
    int to,w; 
    edge(int to,int w):to(to),w(w){}
};
vector<edge>e[maxn];
void link(int u,int v,int w)
{    e[u].push_back(edge(v,w)),e[v].push_back(edge(u,w)); }
void dfs1(int u,int f)
{
    dp[u][0]=dp[u][1]=0;
    for(edge x:e[u]) if(x.to!=f) 
    {
        dfs1(x.to,u);
        int w=dp[x.to][0]+x.w;
        if(w>=dp[u][0]) dp[u][1]=dp[u][0],dp[u][0]=w;
        else dp[u][1]=max(dp[u][1],w);
    }
}
void dfs2(int u,int f,int w)
{
    dp[u][2]=max(dp[f][2],dp[u][0]+w==dp[f][0]?dp[f][1]:dp[f][0])+w;
    for(edge x:e[u]) if(x.to!=f)
        dfs2(x.to,u,x.w);
}
int main()
{
    int n,x,w;
    while(cin>>n)
    {
        for(int i=1;i<=n;i++) e[i].clear();
        for(int i=1;i<n;i++)
            cin>>x>>w,link(i+1,x,w);
        dfs1(1,0),dfs2(1,0,0);
        for(int i=1;i<=n;i++)
            cout<<max(dp[i][0],dp[i][2])<<endl;
    }
}