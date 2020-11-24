#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
vector<int>e[maxn];
void link(int u,int v)
{    e[u].push_back(v),e[v].push_back(u); }
struct PstTrie
{
    int tot,root[maxn],cnt[maxn*40],nxt[maxn*40][2];
    int newnode()
    {
        tot++,cnt[tot]=0;
        nxt[tot][0]=nxt[tot][1]=0;
        return tot;
    }
    void clear()
    {    tot=-1,newnode(),insert(root[0],0,0); }
    void insert(int& rt,int prt,int x)
    {
        rt=++tot;
        bitset<31>b=x;
        int pt=rt;
        for(int i=30;~i;i--)
        {
            nxt[pt][b[i]]=newnode();
            nxt[pt][!b[i]]=nxt[prt][!b[i]];
            pt=nxt[pt][b[i]];
            prt=nxt[prt][b[i]];
            cnt[pt]=cnt[prt]+1;
        }
    }
    int query(int l,int r,int x)
    {
        bitset<31>b=x;
        int lpt=root[l],rpt=root[r],ans=0;
        for(int i=30;~i;i--)
        {
            if(cnt[nxt[rpt][!b[i]]]-cnt[nxt[lpt][!b[i]]])
                lpt=nxt[lpt][!b[i]],rpt=nxt[rpt][!b[i]],ans|=1<<i;
            else lpt=nxt[lpt][b[i]],rpt=nxt[rpt][b[i]];
        }
        return ans;
    }
}t;
int dep[maxn],fat[maxn][20],lg2[maxn]={-1},w[maxn];
void getlg2(int n)
{    for(int i=1;i<=n;i++) lg2[i]=lg2[i>>1]+1; }
void dfs(int u,int f)
{
    dep[u]=dep[f]+1,fat[u][0]=f;
    for(int i=1;(1<<i)<=dep[u];i++)
        fat[u][i]=fat[fat[u][i-1]][i-1];
    t.insert(t.root[u],t.root[f],w[u]);
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
int main()
{
    getlg2(1e5);
    int n,m,u,v,x;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&w[i]),e[i].clear();
        for(int i=1;i<n;i++)
            scanf("%d%d",&u,&v),link(u,v);
        memset(fat,0,sizeof(fat));
        t.clear(),dfs(1,0);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&u,&v,&x);
            int flca=fat[getlca(u,v)][0],ans=0;
            ans=max(ans,t.query(flca,u,x));
            ans=max(ans,t.query(flca,v,x));
            printf("%d\n",ans);
        }
    }
}    