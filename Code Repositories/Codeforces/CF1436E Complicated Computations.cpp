#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
vector<int>idx[maxn];
int tag[maxn],a[maxn],root[maxn];
struct Psdtree
{
	int tot,las[maxn*40],lson[maxn*40],rson[maxn*40];
	void build(int& rt,int l,int r)
	{
		rt=++tot,las[rt]=0;
		if(l==r) return;
		int mid=(l+r)>>1;
		build(lson[rt],l,mid);
		build(rson[rt],mid+1,r);
	}
	void update(int& rt,int prt,int l,int r,int val,int pos)
	{
		rt=++tot;
		lson[rt]=lson[prt],rson[rt]=rson[prt];
		if(l==r) 
		{	las[rt]=pos; return; }
		int mid=(l+r)>>1;
		if(val<=mid) update(lson[rt],lson[prt],l,mid,val,pos);
		else update(rson[rt],rson[prt],mid+1,r,val,pos);
		las[rt]=min(las[lson[rt]],las[rson[rt]]);
	}
	int query(int rt,int l,int r,int pos)
	{
		if(l==r) return l;
		int mid=(l+r)>>1,lpos=las[lson[rt]];
		if(lpos<pos) return query(lson[rt],l,mid,pos);
		else return query(rson[rt],mid+1,r,pos); 
	}
}t;
int main()
{
	int n;
	scanf("%d",&n);
	t.build(root[0],1,n+1);
	for(int i=1;i<=n+1;i++) idx[i].push_back(0);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		t.update(root[i],root[i-1],1,n+1,a[i],i);
		idx[a[i]].push_back(i);
	}
	for(int i=1;i<=n+1;i++) 
	{
		idx[i].push_back(n+1);
		int siz=idx[i].size();
		for(int j=1;j<siz;j++)
		{
			int l=idx[i][j-1]+1,r=idx[i][j]-1;
			if(l>r) continue;
			if(t.query(root[r],1,n+1,l)==i) tag[i]=1;
		}
	}
	int mex=0;
	while(tag[++mex]);
	printf("%d\n",mex);
}