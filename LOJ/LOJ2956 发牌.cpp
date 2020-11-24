#include<bits/stdc++.h>
using namespace std;
const int maxn=7e5+5;
struct WSegtree
{
	int cnt[maxn<<2];
	void push_up(int rt,int lson,int rson)
	{	cnt[rt]=cnt[lson]+cnt[rson]; }
	void build(int rt,int l,int r)
	{
		if(l==r) { cnt[rt]=1; return; }
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
		build(lson,l,mid);
		build(rson,mid+1,r);
		push_up(rt,lson,rson);
	}
	void update(int rt,int l,int r,int pos,int val)
	{
		if(l==r) { cnt[rt]+=val; return; }
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
		if(pos<=mid) update(lson,l,mid,pos,val);
		else update(rson,mid+1,r,pos,val);
		push_up(rt,lson,rson);
	}
	int getkth(int rt,int l,int r,int k)
	{
		if(l==r) return l;
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1,lsiz=cnt[lson];
		if(lsiz>=k) return getkth(lson,l,mid,k);
		else return getkth(rson,mid+1,r,k-lsiz);
	}
}t;
int main()
{
	int n,x,k=1;
	scanf("%d",&n);
	t.build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		k=(k+x)%(n-i+1);
		if(!k) k=n-i+1;
		int kth=t.getkth(1,1,n,k);
		printf("%d\n",kth);
		t.update(1,1,n,kth,-1);
	}
}