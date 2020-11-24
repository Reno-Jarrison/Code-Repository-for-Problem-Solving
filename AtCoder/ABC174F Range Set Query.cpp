#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int pos[maxn],root[maxn];
struct Psdtree
{
	int tot,cnt[maxn*40],lson[maxn*40],rson[maxn*40];
	void update(int& rt,int prt,int l,int r,int pos,int val)
	{
		rt=++tot,cnt[rt]=cnt[prt]+val;
		lson[rt]=lson[prt],rson[rt]=rson[prt];
		if(l==r) return;
		int mid=(l+r)>>1;
		if(pos<=mid) update(lson[rt],lson[prt],l,mid,pos,val);
		else update(rson[rt],rson[prt],mid+1,r,pos,val);
	}
	int query(int rt,int l,int r,int pos)
	{
		if(pos<=l) return cnt[rt];
		int mid=(l+r)>>1;
		if(pos>mid) return query(rson[rt],mid+1,r,pos);
		else return query(lson[rt],l,mid,pos)+cnt[rson[rt]];
	}
}t;
int main()
{
	int n,q,x,l,r;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		t.update(root[i],root[i-1],1,n,i,1);
		if(pos[x])
			t.update(root[i],root[i],1,n,pos[x],-1);
		pos[x]=i;
	}
	while(q--)
	{
		scanf("%d%d",&l,&r);
		printf("%d\n",t.query(root[r],1,n,l));
	}
}