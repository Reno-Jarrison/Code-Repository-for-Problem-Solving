#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5,mod=1e9+7;
struct SegTree
{
    ll sum[maxn<<2],len[maxn<<2];
    ll tagl[maxn<<2],tagr[maxn<<2],tag[maxn<<2];
    void build(int rt,int l,int r)
    {
        sum[rt]=tagl[rt]=tagr[rt]=0;
        len[rt]=r-l+1,tag[rt]=1;
        if(l==r) return;
        int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
        build(lson,l,mid),build(rson,mid+1,r);
    }
    void modify(int rt,int l,int r,ll tl,ll tr,ll t)
    {
        sum[rt]=(sum[rt]*t+tl*len[rt]%mod*t+tr*(r-l+1))%mod;
        len[rt]=len[rt]*t%mod*t%mod;
        tagl[rt]=(tagl[rt]+tag[rt]*tl)%mod;
        tagr[rt]=(tagr[rt]*t+tr)%mod;
        tag[rt]=tag[rt]*t%mod;
    }
    void push_down(int rt,int l,int r)
    {
        if(tag[rt]==1) return;
        int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
        modify(lson,l,mid,tagl[rt],tagr[rt],tag[rt]);
        modify(rson,mid+1,r,tagl[rt],tagr[rt],tag[rt]);
        tagl[rt]=tagr[rt]=0,tag[rt]=1;
    }
    void push_up(int rt,int lson,int rson)
    {    
        sum[rt]=(sum[lson]+sum[rson])%mod;
        len[rt]=(len[lson]+len[rson])%mod; 
    }
    void update(int rt,int l,int r,int L,int R,int val)
    {
        if(L<=l&&r<=R)
        {
            sum[rt]=(sum[rt]*10+len[rt]*10%mod*val+1LL*(r-l+1)*val)%mod;
            len[rt]=len[rt]*100%mod;
            tagl[rt]=(tagl[rt]+tag[rt]*val)%mod;
            tagr[rt]=(tagr[rt]*10+val)%mod;
            tag[rt]=tag[rt]*10%mod;
            return;
        }
        int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
        push_down(rt,l,r);
        if(L<=mid) update(lson,l,mid,L,R,val);
        if(R>mid) update(rson,mid+1,r,L,R,val);
        push_up(rt,lson,rson);
    }
    ll query(int rt,int l,int r,int L,int R)
    {
        if(L<=l&&r<=R) return sum[rt];
        int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
        push_down(rt,l,r);
        ll ans=0;
        if(L<=mid) ans+=query(lson,l,mid,L,R);
        if(R>mid) ans+=query(rson,mid+1,r,L,R);
        return ans%mod;
    }
}t;
int main()
{
    int T,n,m,l,r,val,ks=0;
    char o[10];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        t.build(1,1,n);
        printf("Case %d:\n",++ks);
        for(int i=1;i<=m;i++)
        {
            scanf("%s%d%d",o,&l,&r);
            if(o[0]=='q') printf("%lld\n",t.query(1,1,n,l,r));
            else scanf("%d",&val),t.update(1,1,n,l,r,val);
        }
    }
}