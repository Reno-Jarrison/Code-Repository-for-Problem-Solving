#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
ll mod,x;
int pos[maxn];
struct Segtree
{
	ll mul[maxn<<2];
	void build(int rt,int l,int r)
	{
		if(l==r) { mul[rt]=1; return; }
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
		build(lson,l,mid),build(rson,mid+1,r);
	}
	void push_up(int rt,int lson,int rson)
	{	mul[rt]=mul[lson]*mul[rson]%mod; }
	void update(int rt,int l,int r,int pos,ll val)
	{
		if(l==r) { mul[rt]=val%mod; return; }
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
		if(pos<=mid) update(lson,l,mid,pos,val);
		else update(rson,mid+1,r,pos,val);
		push_up(rt,lson,rson);
	}
	ll query(int rt,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R) return mul[rt];
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
		ll ans=1;
		if(L<=mid) ans=ans*query(lson,l,mid,L,R)%mod;
		if(R>mid) ans=ans*query(rson,mid+1,r,L,R)%mod;
		return ans;
	}
}t;
int main()
{
	int T,n,op,tot;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%lld",&n,&mod);
		t.build(1,1,n),tot=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%lld",&op,&x);
			if(op==1) tot++,t.update(1,1,n,tot,x);
			if(op==2) t.update(1,1,n,pos[x],1);
			pos[i]=tot;
			printf("%lld\n",t.query(1,1,n,1,tot));
		}
	}
}