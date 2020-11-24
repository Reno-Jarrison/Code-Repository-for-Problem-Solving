#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
ll a[maxn];
struct Segtree
{
	ll sum[maxn<<2];
	bool tag[maxn<<2];
	void push_up(int rt,int lson,int rson)
	{
		sum[rt]=sum[lson]+sum[rson];
		tag[rt]=tag[lson]&&tag[rson];
	}
	void build(int rt,int l,int r,ll* src)
	{
		if(l==r)
		{	sum[rt]=src[l],tag[rt]=(src[l]<=1); return; }
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
		build(lson,l,mid,src);
		build(rson,mid+1,r,src);
		push_up(rt,lson,rson);
	}
	void update(int rt,int l,int r,int L,int R)
	{
		if(tag[rt]) return;
		if(l==r)
		{
			sum[rt]=sqrt(sum[rt]);
			tag[rt]=(sum[rt]==1);
			return;
		}
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
		if(L<=mid) update(lson,l,mid,L,R);
		if(R>mid) update(rson,mid+1,r,L,R);
		push_up(rt,lson,rson);
	}
	ll query(int rt,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R) return sum[rt];
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
		ll ans=0;
		if(L<=mid) ans+=query(lson,l,mid,L,R);
		if(R>mid) ans+=query(rson,mid+1,r,L,R);
		return ans;
	}
}t;
int main()
{
	int n,m,o,l,r;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	t.build(1,1,n,a);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&o,&l,&r);
		if(o==1) printf("%lld\n",t.query(1,1,n,l,r));
		if(o==2) t.update(1,1,n,l,r);
	}
}