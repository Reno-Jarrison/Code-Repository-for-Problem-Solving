#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5;
int a[maxn];
struct Segtree
{
    ll mxv[maxn<<2],sec[maxn<<2];
    ll cnt[maxn<<2],sum[maxn<<2];
    void push_up(int rt,int lson,int rson)
    {
        sum[rt]=sum[lson]+sum[rson],cnt[rt]=0;
        mxv[rt]=max(mxv[lson],mxv[rson]);
        sec[rt]=max(sec[lson],sec[rson]);
        if(mxv[lson]!=mxv[rson])
            sec[rt]=max(sec[rt],min(mxv[lson],mxv[rson]));
        if(mxv[rt]==mxv[lson]) cnt[rt]+=cnt[lson];
        if(mxv[rt]==mxv[rson]) cnt[rt]+=cnt[rson];
    }
    void modify(int rt,int val)
    {
        if(mxv[rt]<=val) return;
        sum[rt]-=cnt[rt]*(mxv[rt]-val),mxv[rt]=val;
    }
    void push_down(int rt,int lson,int rson)
    {   modify(lson,mxv[rt]),modify(rson,mxv[rt]); }
    void build(int rt,int l,int r,int* src)
    {
        if(l==r) 
        {   mxv[rt]=sum[rt]=src[l],sec[rt]=-1,cnt[rt]=1; return; }
        int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
        build(lson,l,mid,src);
        build(rson,mid+1,r,src);
        push_up(rt,lson,rson);
    }
    void update(int rt,int l,int r,int L,int R,int val)
    {
        if(L<=l&&r<=R&&sec[rt]<val)
        {   modify(rt,val); return; }
        int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
        push_down(rt,lson,rson);
        if(L<=mid) update(lson,l,mid,L,R,val);
        if(R>mid) update(rson,mid+1,r,L,R,val);
        push_up(rt,lson,rson);
    }
    ll query(int rt,int l,int r,int L,int R,int flag)
    {
        if(L<=l&&r<=R) return flag==1?mxv[rt]:sum[rt];
        int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
        push_down(rt,lson,rson);
        ll ans=0,lans=0,rans=0;
        if(L<=mid) lans=query(lson,l,mid,L,R,flag);
        if(L<=mid) ans=flag==1?max(ans,lans):ans+lans;
        if(R>mid) rans=query(rson,mid+1,r,L,R,flag);
        if(R>mid) ans=flag==1?max(ans,rans):ans+rans;
        return ans;
    }
}t;
int main()
{
    int T,n,m,l,r,o,x;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        t.build(1,1,n,a);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&o,&l,&r);
            if(!o) scanf("%d",&x),t.update(1,1,n,l,r,x);
            else printf("%lld\n",t.query(1,1,n,l,r,o));
        }
    }
}