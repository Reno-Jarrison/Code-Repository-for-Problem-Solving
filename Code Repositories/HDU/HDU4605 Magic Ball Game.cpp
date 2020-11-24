#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,inf=0x3f3f3f3f;
struct PsdTree
{
    int tot,lson[maxn*40],rson[maxn*40],cnt[maxn*40][2];
    void modify(int& rt,int prt,int l,int r,int val,int tag)
    {
        rt=++tot;
        lson[rt]=lson[prt],rson[rt]=rson[prt];
        cnt[rt][0]=cnt[prt][0],cnt[rt][1]=cnt[prt][1];
        cnt[rt][tag]++;
        if(l==r) return;
        int mid=(l+r)>>1;
        if(val<=mid) modify(lson[rt],lson[prt],l,mid,val,tag);
        else modify(rson[rt],rson[prt],mid+1,r,val,tag);
    }
    int query(int rt,int l,int r,int L,int R,int tag)
    {
        if(L<=l&&r<=R) return cnt[rt][tag];
        int mid=(l+r)>>1,ans=0;
        if(L<=mid) ans+=query(lson[rt],l,mid,L,R,tag);
        if(R>mid) ans+=query(rson[rt],mid+1,r,L,R,tag);
        return ans;
    }
}t;
int w[maxn],root[maxn];
vector<int>e[maxn];
void link(int u,int a,int b)
{    e[u].push_back(a),e[u].push_back(b); }
void dfs(int u)
{
    int dir=0;
    for(int v:e[u])
        t.modify(root[v],root[u],1,inf,w[u],dir++),dfs(v);
}
int main()
{
    int T,n,m,q,u,a,b,v,x;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&w[i]),e[i].clear();
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
            scanf("%d%d%d",&u,&a,&b),link(u,a,b);
        t.tot=0,memset(t.cnt,0,sizeof(t.cnt)),dfs(1);
        scanf("%d",&q);
        for(int i=1;i<=q;i++)
        {
            scanf("%d%d",&v,&x);
            int numx=t.query(root[v],1,inf,x,x,0)+t.query(root[v],1,inf,x,x,1);
            if(numx)
            {    puts("0"); continue; }
            int numl0=t.query(root[v],1,inf,1,x,0);
            int numl1=t.query(root[v],1,inf,1,x,1);
            int numr0=t.query(root[v],1,inf,x,inf,0);
            int numr1=t.query(root[v],1,inf,x,inf,1);
            printf("%d %d\n",numl1,3*(numl0+numl1)+numr0+numr1);
        }
    }
}