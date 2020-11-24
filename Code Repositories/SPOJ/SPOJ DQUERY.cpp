#include<bits/stdc++.h>
using namespace std;
const int maxn=3e4+5,maxm=1e6+5;
struct Psdtree
{
	int tot,lson[maxn*40],rson[maxn*40],cnt[maxn*40];
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
		if(pos<=mid) return query(lson[rt],l,mid,pos)+cnt[rson[rt]];
		else return query(rson[rt],mid+1,r,pos);
	}
}t;
int root[maxn],pos[maxm];
int main()
{
	int n,a,q,l,r;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a);
		t.update(root[i],root[i-1],1,n,i,1);
		if(pos[a])
			t.update(root[i],root[i],1,n,pos[a],-1);
		pos[a]=i;
	}
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&l,&r);
		printf("%d\n",t.query(root[r],1,n,l));
	}
}