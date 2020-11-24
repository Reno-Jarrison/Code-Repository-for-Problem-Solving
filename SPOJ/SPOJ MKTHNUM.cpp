#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int cnt,uni,a[maxn],dct[maxn],root[maxn];
struct node
{	int num,l,r; }t[maxn<<5];
int build(int l,int r)
{
	int rt=++cnt,mid=(l+r)>>1;
	t[rt].num=0;
	if(l<r)
	{
		t[rt].l=build(l,mid);
		t[rt].r=build(mid+1,r);
	}
	return rt;
}
int update(int prt,int l,int r,int val)
{
	int rt=++cnt,mid=(l+r)>>1;
	t[rt].l=t[prt].l,t[rt].r=t[prt].r;
	t[rt].num=t[prt].num+1;
	if(l<r)
	{
		if(val<=mid) t[rt].l=update(t[prt].l,l,mid,val);
		else t[rt].r=update(t[prt].r,mid+1,r,val);
	}
	return rt;
}
int query(int L,int R,int l,int r,int k)
{
	if(l>=r) return l;
	int mid=(l+r)>>1;
	int count=t[t[R].l].num-t[t[L].l].num;
	if(count>=k) return query(t[L].l,t[R].l,l,mid,k);
	else return query(t[L].r,t[R].r,mid+1,r,k-count);
}
int main()
{
	int n,m,l,r,k;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),dct[i]=a[i];
	sort(dct+1,dct+n+1);
	uni=unique(dct+1,dct+n+1)-dct-1;
	root[0]=build(1,uni);
	for(int i=1;i<=n;i++)
	{
		int x=lower_bound(dct+1,dct+uni+1,a[i])-dct;
		root[i]=update(root[i-1],1,uni,x);
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&l,&r,&k);
		printf("%d\n",dct[query(root[l-1],root[r],1,uni,k)]);
	}
}
