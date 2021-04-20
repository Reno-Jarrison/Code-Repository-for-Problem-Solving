#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
char s[maxn],f[maxn];
struct Segtree
{
	int cnt[maxn<<2],tag[maxn<<2];
	void push_up(int rt,int lson,int rson)
	{	cnt[rt]=cnt[lson]+cnt[rson]; }
	void push_down(int rt,int l,int r)
	{
		if(tag[rt]==-1) return;
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
		modify(lson,l,mid,tag[rt]);
		modify(rson,mid+1,r,tag[rt]);
		tag[rt]=-1;
	}
	void modify(int rt,int l,int r,int val)
	{	cnt[rt]=val*(r-l+1),tag[rt]=val; }
	void build(int rt,int l,int r)
	{
		tag[rt]=-1;
		if(l==r) 
		{	cnt[rt]=f[l]-'0'; return; }
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
		build(lson,l,mid);
		build(rson,mid+1,r);
		push_up(rt,lson,rson);
	}
	void update(int rt,int l,int r,int L,int R,int val)
	{
		if(L<=l&&r<=R)
		{	cnt[rt]=val*(r-l+1),tag[rt]=val; return; }
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
		push_down(rt,l,r);
		if(L<=mid) update(lson,l,mid,L,R,val);
		if(R>mid) update(rson,mid+1,r,L,R,val);
		push_up(rt,lson,rson);
	}
	int query(int rt,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R) return cnt[rt];
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1,ans=0;
		push_down(rt,l,r);
		if(L<=mid) ans+=query(lson,l,mid,L,R);
		if(R>mid) ans+=query(rson,mid+1,r,L,R);
		return ans;
	}
}t;
int ql[maxn],qr[maxn];
int main()
{
	int T,n,q;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&q);
		scanf("%s%s",s+1,f+1);
		t.build(1,1,n);
		for(int i=1;i<=q;i++)
			scanf("%d%d",&ql[i],&qr[i]);
		int ok=1;
		for(int i=q;i&&ok;i--)
		{
			int cnt=t.query(1,1,n,ql[i],qr[i]),tot=qr[i]-ql[i]+1;
			if(cnt*2==tot) ok=0;
			else t.update(1,1,n,ql[i],qr[i],cnt*2>tot);
		}
		for(int i=1;i<=n&&ok;i++)
			if(t.query(1,1,n,i,i)!=s[i]-'0') ok=0;
		puts(ok?"YES":"NO");
	}
}