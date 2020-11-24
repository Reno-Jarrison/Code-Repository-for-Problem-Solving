#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,inf=1e9;
struct PstTree
{
	int tot,sum[maxn*40],lson[maxn*40],rson[maxn*40];
	void update(int& rt,int prt,int l,int r,int val)
	{
		rt=++tot,sum[rt]=sum[prt]+val;
		lson[rt]=lson[prt],rson[rt]=rson[prt];
		if(l==r) return;
		int mid=(l+r)>>1;
		if(val<=mid) update(lson[rt],lson[prt],l,mid,val);
		else update(rson[rt],rson[prt],mid+1,r,val);
	}
	int query(int lrt,int rrt,int l,int r,int val)
	{
		if(l==r) return sum[rrt]-sum[lrt];
		int mid=(l+r)>>1,lsum=sum[lson[rrt]]-sum[lson[lrt]];
		if(val<=mid) return query(lson[lrt],lson[rrt],l,mid,val);
		else return lsum+query(rson[lrt],rson[rrt],mid+1,r,val);
	}
}t;
int root[maxn];
int main()
{
	int n,m,x,l,r;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&x),t.update(root[i],root[i-1],1,inf,x);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&l,&r);
		int lrt=root[l-1],rrt=root[r],ans=1;
		while(true)
		{
			int cur=t.query(lrt,rrt,1,inf,ans);
			if(cur>=ans) ans=cur+1;
			else break;
		}
		printf("%d\n",ans);
	}
}