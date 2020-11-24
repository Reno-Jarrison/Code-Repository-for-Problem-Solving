#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
struct PsdTree
{
	ll sum[maxn*40];
	int tot,cnt[maxn*40],lson[maxn*40],rson[maxn*40];
	void update(int& rt,int prt,int l,int r,int pos,int val)
	{
		rt=++tot,sum[rt]=sum[prt]+val;
		cnt[rt]=cnt[prt]+val/abs(val);
		lson[rt]=lson[prt],rson[rt]=rson[prt];
		if(l==r) return;
		int mid=(l+r)>>1;
		if(pos<=mid) update(lson[rt],lson[prt],l,mid,pos,val);
		else update(rson[rt],rson[prt],mid+1,r,pos,val);
	}
	ll query(int rt,int l,int r,int k)
	{
		if(l==r) return k?sum[rt]/cnt[rt]*k:0;
		int mid=(l+r)>>1,lsiz=cnt[lson[rt]];
		if(lsiz>=k) return query(lson[rt],l,mid,k);
		else return sum[lson[rt]]+query(rson[rt],mid+1,r,k-lsiz);
	}
}t;
int root[maxn],d[maxn];
vector<int>vec[maxn];
int main()
{
	int n,m,l,r,x,pos,a,b,c,k;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&l,&r,&x);
		vec[l].push_back(x);
		vec[r+1].push_back(-x);
		d[i]=x;
	}
	sort(d+1,d+m+1);
	int uni=unique(d+1,d+m+1)-d-1;
	for(int i=1;i<=n;i++)
	{
		root[i]=root[i-1];
		for(int x:vec[i])
		{
			int pos=lower_bound(d+1,d+uni+1,abs(x))-d;
			t.update(root[i],root[i],1,uni,pos,x);
		}
	}
	ll ans=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&pos,&a,&b,&c);
		k=min(1+(1LL*a*ans+b)%c,1LL*t.cnt[root[pos]]);
		ans=t.query(root[pos],1,uni,k);	
		printf("%lld\n",ans);
	}
}