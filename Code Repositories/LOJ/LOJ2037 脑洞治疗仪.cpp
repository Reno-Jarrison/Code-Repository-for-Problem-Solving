#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
struct node
{
	int cnt,lcnt,rcnt;
	node(int c=0,int l=0,int r=0):cnt(c),lcnt(l),rcnt(r){}
};
struct Segtree
{
	int sum[maxn<<2],len[maxn<<2],tag[maxn<<2];
	int cnt[maxn<<2],lcnt[maxn<<2],rcnt[maxn<<2];
	void modify(int rt,int val)
	{
		sum[rt]=val*len[rt],tag[rt]=val;
		cnt[rt]=lcnt[rt]=rcnt[rt]=(val^1)*len[rt];
	}
	void push_down(int rt,int lson,int rson)
	{
		if(tag[rt]==-1) return;
		modify(lson,tag[rt]);
		modify(rson,tag[rt]);
		tag[rt]=-1;
	}
	void push_up(int rt,int lson,int rson)
	{
		sum[rt]=sum[lson]+sum[rson];
		cnt[rt]=max(cnt[lson],cnt[rson]);
		cnt[rt]=max(cnt[rt],rcnt[lson]+lcnt[rson]);
		lcnt[rt]=lcnt[lson]==len[lson]?len[lson]+lcnt[rson]:lcnt[lson];
		rcnt[rt]=rcnt[rson]==len[rson]?len[rson]+rcnt[lson]:rcnt[rson];
	}
	void build(int rt,int l,int r)
	{
		sum[rt]=len[rt]=r-l+1,tag[rt]=-1;
		if(l==r) return;
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
		build(lson,l,mid);
		build(rson,mid+1,r);
	}
	int update1(int rt,int l,int r,int L,int R,int val)
	{
		if(L<=l&&r<=R)
		{
			int ans=sum[rt];
			modify(rt,val);
			return ans;
		}
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1,ans=0;
		push_down(rt,lson,rson);
		if(L<=mid) ans+=update1(lson,l,mid,L,R,val);
		if(R>mid) ans+=update1(rson,mid+1,r,L,R,val);
		push_up(rt,lson,rson);
		return ans;
	}
	int update2(int rt,int l,int r,int L,int R,int val)
	{
		if(!val) return 0;
		if(L<=l&&r<=R&&len[rt]-sum[rt]<=val)
		{	
			int ans=len[rt]-sum[rt];
			modify(rt,1); 
			return val-ans; 
		}
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
		push_down(rt,lson,rson);
		if(L<=mid) val=update2(lson,l,mid,L,R,val);
		if(R>mid) val=update2(rson,mid+1,r,L,R,val);
		push_up(rt,lson,rson);
		return val;
	}
	node query(int rt,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R) return node(cnt[rt],lcnt[rt],rcnt[rt]);
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
		push_down(rt,lson,rson);
		node ans,lans,rans;
		if(L<=mid) lans=query(lson,l,mid,L,R);
		if(R>mid) rans=query(rson,mid+1,r,L,R);
		ans.cnt=max(lans.cnt,rans.cnt);
		ans.cnt=max(ans.cnt,lans.rcnt+rans.lcnt);
		ans.lcnt=lans.cnt==len[lson]?len[lson]+rans.lcnt:lans.lcnt;
		ans.rcnt=rans.cnt==len[rson]?len[rson]+lans.rcnt:rans.rcnt;
		return ans;
	}
}t;
int main()
{
	int n,m,o,l0,r0,l1,r1;
	scanf("%d%d",&n,&m);
	t.build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&o,&l0,&r0);
		if(o==0) t.update1(1,1,n,l0,r0,0);
		if(o==1)
		{
			scanf("%d%d",&l1,&r1);
			int num=t.update1(1,1,n,l0,r0,0);
			t.update2(1,1,n,l1,r1,num);
		}
		if(o==2) printf("%d\n",t.query(1,1,n,l0,r0).cnt);
	}

}