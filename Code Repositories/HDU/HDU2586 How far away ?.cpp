#include<bits/stdc++.h>
using namespace std;
const int maxn=4e4+5;
struct edge
{
    int to,w;
    edge(int to,int w):to(to),w(w){}
};
vector<edge>e[maxn];
int dep[maxn],dis[maxn],fat[maxn][20],lg2[maxn]={-1};
void link(int u,int v,int w)
{    e[u].push_back(edge(v,w)),e[v].push_back(edge(u,w)); }
void getlg2(int n)
{    for(int i=1;i<=n;i++) lg2[i]=lg2[i>>1]+1; }
void dfs(int u,int f)
{
    dep[u]=dep[f]+1,fat[u][0]=f;
    for(int i=1;(1<<i)<=dep[u];i++)
        fat[u][i]=fat[fat[u][i-1]][i-1];
    for(edge x:e[u])
    {
        int v=x.to,w=x.w;
        if(v==f) continue;
        dis[v]=dis[u]+w,dfs(v,u);
    }
}
int lca(int x,int y)
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
int getdis(int x,int y)
{    return dis[x]+dis[y]-dis[lca(x,y)]*2; }
int main()
{
    getlg2(40000);
    int t,n,m,u,v,w;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) e[i].clear();
        for(int i=1;i<n;i++)
            scanf("%d%d%d",&u,&v,&w),link(u,v,w);
        dfs(1,0);
        for(int i=1;i<=m;i++)
            scanf("%d%d",&u,&v),printf("%d\n",getdis(u,v));
    }
}