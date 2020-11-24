#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5,inf=0x3f3f3f3f;
struct node
{	int l,r,len; }p[maxn];
int tot,idx[maxn*2],mp[maxn*2];
bool operator <(const node& x,const node& y)
{	return x.r-x.l<y.r-y.l; }
struct Segtree
{
	int mxv[maxn<<3],tag[maxn<<3];
	void modify(int rt,int val)
	{	mxv[rt]+=val,tag[rt]+=val; }
	void push_down(int rt,int lson,int rson)
	{
		modify(lson,tag[rt]);
		modify(rson,tag[rt]);
		tag[rt]=0;
	}
	void push_up(int rt,int lson,int rson)
	{	mxv[rt]=max(mxv[lson],mxv[rson]); }
	void update(int rt,int l,int r,int L,int R,int val)
	{
		if(L<=l&&r<=R) { modify(rt,val); return; }
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
		push_down(rt,lson,rson);
		if(L<=mid) update(lson,l,mid,L,R,val);
		if(R>mid) update(rson,mid+1,r,L,R,val);
		push_up(rt,lson,rson);
	}
}t;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&p[i].l,&p[i].r);
		idx[i]=p[i].l,idx[i+n]=p[i].r;
	}
	sort(idx+1,idx+n*2+1),idx[0]=-1;
	for(int i=1;i<=n*2;i++)
		if(idx[i]!=idx[i-1]) mp[++tot]=idx[i];
	sort(p+1,p+n+1);
	int las=1,ans=inf;
	for(int i=1;i<=n;i++)
	{
		p[i].len=p[i].r-p[i].l;
		p[i].l=lower_bound(mp+1,mp+tot+1,p[i].l)-mp;
		p[i].r=lower_bound(mp+1,mp+tot+1,p[i].r)-mp;
		t.update(1,1,tot,p[i].l,p[i].r,1);
		while(t.mxv[1]==m)
		{
			ans=min(ans,p[i].len-p[las].len);
			t.update(1,1,tot,p[las].l,p[las].r,-1),las++;
		}
	}
	if(ans==inf) ans=-1;
	printf("%d\n",ans);
}