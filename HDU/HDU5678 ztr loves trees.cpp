#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
const double mod=1e9+7;
vector<int>e[maxn];
void link(int u,int v)
{    e[u].push_back(v),e[v].push_back(u); }
struct PsdTree
{
    int tot,lson[maxn*40],rson[maxn*40],cnt[maxn*40];
    void modify(int& rt,int prt,int l,int r,int val)
    {
        rt=++tot;
        lson[rt]=lson[prt],rson[rt]=rson[prt];
        cnt[rt]=cnt[prt]+1;
        if(l==r) return;
        int mid=(l+r)>>1;
        if(val<=mid) modify(lson[rt],lson[prt],l,mid,val);
        else modify(rson[rt],rson[prt],mid+1,r,val);
    }
    int query(int lrt,int rrt,int l,int r,int k)
    {
        if(l==r) return l;
        int mid=(l+r)>>1,lsiz=cnt[lson[rrt]]-cnt[lson[lrt]];
        if(k<=lsiz) return query(lson[lrt],lson[rrt],l,mid,k);
        else return query(rson[lrt],rson[rrt],mid+1,r,k-lsiz);
    }
}t;
int w[maxn],d[maxn],root[maxn],siz[maxn],dfn[maxn],tid[maxn],idx;
void dfs(int u,int f)
{
    siz[u]=1,dfn[u]=++idx,tid[idx]=u;
    for(int v:e[u])
        if(v!=f) dfs(v,u),siz[u]+=siz[v];
}
double ans[maxn],res;
int main()
{
    int T,n,m,u,v,x;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&w[i]),d[i]=w[i],e[i].clear();
        for(int i=1;i<n;i++)
            scanf("%d%d",&u,&v),link(u,v);
        t.tot=idx=0,res=0,dfs(1,0);
        sort(d+1,d+n+1);
        int uni=unique(d+1,d+n+1)-d-1;
        for(int i=1;i<=n;i++)
            w[i]=lower_bound(d+1,d+uni+1,w[i])-d;
        for(int i=1;i<=n;i++)
            t.modify(root[i],root[i-1],1,uni,w[tid[i]]);
        for(int i=1;i<=n;i++)
        {
            int lrt=root[dfn[i]-1],rrt=root[dfn[i]+siz[i]-1];
            if(siz[i]&1)
                ans[i]=(double)d[t.query(lrt,rrt,1,uni,(siz[i]+1)/2)];
            else
            {
                int tmp1=t.query(lrt,rrt,1,uni,siz[i]/2);
                int tmp2=t.query(lrt,rrt,1,uni,siz[i]/2+1);
                ans[i]=(d[tmp1]+d[tmp2])/2.0;
            }
        }
        for(int i=1;i<=m;i++)
            scanf("%d",&x),res=fmod(res*10+ans[x],mod);
        printf("%.1lf\n",res);
    }
}