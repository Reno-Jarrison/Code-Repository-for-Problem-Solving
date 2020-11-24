#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+5;
int idx[maxn],a[maxn];
struct Segtree
{
	int mxv[maxn<<2];
	void build(int rt,int l,int r,int* src)
	{
		if(l==r) { mxv[rt]=src[l]; return; }
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
		build(lson,l,mid,src);
		build(rson,mid+1,r,src);
		mxv[rt]=max(mxv[lson],mxv[rson]);
	}
	int query(int rt,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R) return mxv[rt];
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1,ans=0;
		if(L<=mid) ans=max(ans,query(lson,l,mid,L,R));
		if(R>mid) ans=max(ans,query(rson,mid+1,r,L,R));
		return ans;
	}
}t;
int main()
{
	int n,m,l,r;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&idx[i],&a[i]);
	t.build(1,1,n,a);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		if(l>=r) { puts("false"); continue; }
		int xl=lower_bound(idx+1,idx+n+1,l)-idx;
		int xr=lower_bound(idx+1,idx+n+1,r)-idx;
		int tagl=idx[xl]==l,tagr=idx[xr]==r;
		if(!tagl) xl--;
		int mxv=xl+1>=xr?0:t.query(1,1,n,xl+1,xr-1);
		if((tagr&&mxv>=a[xr])||(tagl&&mxv>=a[xl])||(tagl&&tagr&&a[xl]<a[xr]))
		{	puts("false"); continue; }
		puts(xr-xl!=idx[xr]-idx[xl]||!tagl||!tagr?"maybe":"true");
	}
}