#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=3e5+5,mod=1e9+9;
int src[maxn],f[maxn];
struct Segtree
{
	int sum[maxn<<2],tag1[maxn<<2],tag2[maxn<<2];
	void push_up(int rt,int lson,int rson)
	{	sum[rt]=(sum[lson]+sum[rson])%mod; }
	void modify(int rt,int val1,int val2,int n)
	{
		tag1[rt]=(tag1[rt]+val1)%mod;
		tag2[rt]=(tag2[rt]+val2)%mod;
		int cur=(1ll*val2*f[n+1]+1ll*val1*f[n]-val2+mod)%mod;
		sum[rt]=(sum[rt]+cur)%mod;
	}
	void push_down(int rt,int l,int r)
	{
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
		int lval1=tag1[rt],lval2=tag2[rt];
		int rval1=(1ll*lval2*f[mid-l+1]+1ll*lval1*f[mid-l])%mod;
		int rval2=(1ll*lval2*f[mid-l+2]+1ll*lval1*f[mid-l+1])%mod;
		modify(lson,lval1,lval2,mid-l+1);
		modify(rson,rval1,rval2,r-mid);
		tag1[rt]=tag2[rt]=0;
	}
	void build(int rt,int l,int r)
	{
		if(l==r) 
		{	sum[rt]=src[l]; return; }
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
		build(lson,l,mid);
		build(rson,mid+1,r);
		push_up(rt,lson,rson);
	}
	void update(int rt,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R)
		{
			int id=l-L+1;
			modify(rt,f[id],f[id+1],r-l+1);
			return;
		}
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
		push_down(rt,l,r);
		if(L<=mid) update(lson,l,mid,L,R);
		if(R>mid) update(rson,mid+1,r,L,R);
		push_up(rt,lson,rson);
	}
	int query(int rt,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R) return sum[rt];
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
		push_down(rt,l,r);
		int ans=0;
		if(L<=mid) ans=(ans+query(lson,l,mid,L,R))%mod;
		if(R>mid) ans=(ans+query(rson,mid+1,r,L,R))%mod;
		return ans;
	}
}t;
int main()
{
	int n,m,o,l,r;
	scanf("%d%d",&n,&m);
	f[1]=f[2]=1;
	for(int i=3;i<=n+1;i++)
		f[i]=(f[i-1]+f[i-2])%mod;
	for(int i=1;i<=n;i++)
		scanf("%d",&src[i]);
	t.build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&o,&l,&r);
		if(o==1)
			t.update(1,1,n,l,r);
		if(o==2)
			printf("%d\n",t.query(1,1,n,l,r));
	}
}