#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
int id[maxn];
ll src[maxn],p[maxn],k,x;
vector<int>vec[maxn];
struct node
{	
	ll mxv,sum; int idx; 
	node(ll m=(ll)1e-18,ll s=0,int i=0):
		mxv(m),sum(s),idx(i){}
};
struct SegTree
{
	ll sum[maxn<<2],mxv[maxn<<2],idx[maxn<<2];
	void push_up(int rt,int lson,int rson)
	{
		sum[rt]=sum[lson]+sum[rson];
		mxv[rt]=max(mxv[lson],sum[lson]+mxv[rson]);
		idx[rt]=(mxv[rt]==mxv[lson]?idx[lson]:idx[rson]);
	}
	void build(int rt,int l,int r,ll* src)
	{
		if(l==r) 
			return (void)(sum[rt]=mxv[rt]=src[l],idx[rt]=l);
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
		build(lson,l,mid,src);
		build(rson,mid+1,r,src);
		push_up(rt,lson,rson);
	}
	void update(int rt,int l,int r,int pos,ll val)
	{
		if(l==r) return (void)(sum[rt]+=val,mxv[rt]+=val);
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
		if(pos<=mid) update(lson,l,mid,pos,val);
		else update(rson,mid+1,r,pos,val);
		push_up(rt,lson,rson);
	}
	node query(int rt,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R) return node(mxv[rt],sum[rt],idx[rt]);
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
		node ans,lans,rans;
		if(L<=mid) lans=query(lson,l,mid,L,R);
		if(R>mid) rans=query(rson,mid+1,r,L,R);
		ans.mxv=max(lans.mxv,lans.sum+rans.mxv);
		ans.sum=lans.sum+rans.sum;
		ans.idx=(ans.mxv==lans.mxv?lans.idx:rans.idx);
		return ans;
	}
}t;
int main()
{
	int n,l,r,tot=0;
	scanf("%d%lld",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%lld",&l,&r,&x);
		tot=max(tot,r),src[r]+=x;
		vec[l].push_back(i);
		id[i]=r,p[i]=x;
	}
	for(int i=1;i<=tot;i++) src[i]-=k;
	t.build(1,1,tot,src);
	ll ans=0;
	int lx,rx;
	for(int i=1;i<=tot;i++)
	{
		auto cur=t.query(1,1,tot,i,tot);
		if(cur.mxv>ans)
			ans=cur.mxv,lx=i,rx=cur.idx;
		for(int x:vec[i])
			t.update(1,1,tot,id[x],-p[x]);
	}
	if(ans==0) puts("0");
	else
	{
		vector<int>s;
		for(int i=lx;i<=rx;i++)
			for(int x:vec[i])
				if(id[x]<=rx) s.push_back(x);
		int size=s.size();
		printf("%lld %d %d %d\n",ans,lx,rx,size);
		for(int i=0;i<size;i++)
			printf("%d%c",s[i],i==size-1?'\n':' ');
	}
}