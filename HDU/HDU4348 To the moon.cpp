#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int src[maxn],root[maxn];
struct PsdTree
{
    int tot,lson[maxn*30],rson[maxn*30];
    ll sum[maxn*30],tag[maxn*30];
    void build(int& rt,int l,int r)
    {
        rt=++tot,tag[rt]=0;
        if(l==r)
        {    sum[rt]=src[l]; return; }
        int mid=(l+r)>>1;
        build(lson[rt],l,mid);
        build(rson[rt],mid+1,r);
        sum[rt]=sum[lson[rt]]+sum[rson[rt]];
    }
    void update(int& rt,int prt,int l,int r,int L,int R,int val)
    {
        rt=++tot;
        lson[rt]=lson[prt],rson[rt]=rson[prt];
        sum[rt]=sum[prt],tag[rt]=tag[prt];
        sum[rt]+=1LL*val*(min(R,r)-max(L,l)+1);
        if(L<=l&&r<=R)
        {    tag[rt]+=val; return; }
        int mid=(l+r)>>1;
        if(L<=mid) update(lson[rt],lson[prt],l,mid,L,R,val);
        if(R>mid) update(rson[rt],rson[prt],mid+1,r,L,R,val);
    }
    ll query(int rt,int l,int r,int L,int R,ll tmp)
    {
        if(L<=l&&r<=R) return sum[rt]+tmp*(r-l+1);
        int mid=(l+r)>>1; ll ans=0;
        if(L<=mid) ans+=query(lson[rt],l,mid,L,R,tmp+tag[rt]);
        if(R>mid) ans+=query(rson[rt],mid+1,r,L,R,tmp+tag[rt]);
        return ans;
    }
}t;
int main()
{
    int n,m,l,r,x,T;
    char o[3];
    while(~scanf("%d%d",&n,&m))
    {
        int idx=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&src[i]);
        t.tot=0,t.build(root[0],1,n);
        for(int i=1;i<=m;i++)
        {
            scanf("%s",o);
            if(o[0]=='C')
            {
                scanf("%d%d%d",&l,&r,&x);
                t.update(root[idx+1],root[idx],1,n,l,r,x),idx++;
            }
            if(o[0]=='Q')
            {
                scanf("%d%d",&l,&r);
                printf("%lld\n",t.query(root[idx],1,n,l,r,0));
            }
            if(o[0]=='H')
            {
                scanf("%d%d%d",&l,&r,&T);
                printf("%lld\n",t.query(root[T],1,n,l,r,0));
            }
            if(o[0]=='B') scanf("%d",&idx);
        }
    }
}
