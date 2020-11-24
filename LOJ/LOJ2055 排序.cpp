#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=4e5+5;
struct node
{	
	int l,r,rt,tag;
	node(int l,int r,int rt,int tag=0):
		l(l),r(r),rt(rt),tag(tag){}
};
bool operator <(const node& x,const node& y)
{	return x.r<y.r||(x.r==y.r&&x.l<y.l); }
set<node>st;
set<node>::iterator it;
struct WSegTree
{
	int tot,lrt[maxn*40],rrt[maxn*40],cnt[maxn*40];
	void insert(int& rt,int l,int r,int pos)
	{
		rt=++tot,cnt[rt]++;
		if(l==r) return;
		int mid=(l+r)>>1;
		if(pos<=mid) insert(lrt[rt],l,mid,pos);
		else insert(rrt[rt],mid+1,r,pos);
	}
	void push_up(int rt,int lson,int rson)
	{	cnt[rt]=cnt[lson]+cnt[rson]; }
	void merge(int& x,int y,int l,int r)
	{
		if(!x||!y) { x|=y; return; }
		if(l==r) { cnt[x]+=cnt[y]; return; }
		int mid=(l+r)>>1;
		merge(lrt[x],lrt[y],l,mid);
		merge(rrt[x],rrt[y],mid+1,r);
		push_up(x,lrt[x],rrt[x]);
	}
	void split(int x,int& y,int l,int r,int k,int tag)
	{
		if(!x) return;
		if(!y) y=++tot;
		if(l==r) { cnt[x]-=k,cnt[y]+=k; return; }
		int mid=(l+r)>>1;
		if(tag)
		{
			int rsiz=cnt[rrt[x]];
			if(rsiz>=k) split(rrt[x],rrt[y],mid+1,r,k,tag);
			else rrt[y]=rrt[x],rrt[x]=0,split(lrt[x],lrt[y],l,mid,k-rsiz,tag); 
		}
		else
		{
			int lsiz=cnt[lrt[x]];
			if(lsiz>=k) split(lrt[x],lrt[y],l,mid,k,tag);
			else lrt[y]=lrt[x],lrt[x]=0,split(rrt[x],rrt[y],mid+1,r,k-lsiz,tag);
		}
		push_up(x,lrt[x],rrt[x]);
		push_up(y,lrt[y],rrt[y]);
	}
	int getkth(int rt,int l,int r,int k)
	{
		if(l==r) return l;
		int mid=(l+r)>>1,lsiz=cnt[lrt[rt]];
		if(k<=lsiz) return getkth(lrt[rt],l,mid,k);
		else return getkth(rrt[rt],mid+1,r,k-lsiz);
	}
}t;
int main()
{
	int n,m,x,o,l,r;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int rt=0;
		scanf("%d",&x),t.insert(rt,1,n,x);
		st.insert(node(i,i,rt));
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&o,&l,&r);
		it=st.lower_bound(node(0,l,0));
		if(l>it->l)
		{
			int rrt=it->rt,lrt=0,itl=it->l,itr=it->r,tag=it->tag;
			t.split(rrt,lrt,1,n,l-itl,tag);
			st.erase(it);
			st.insert(node(itl,l-1,lrt,tag));
			st.insert(node(l,itr,rrt,tag));
		}
		it=st.lower_bound(node(0,r,0));
		if(r<it->r)
		{
			int rrt=it->rt,lrt=0,itl=it->l,itr=it->r,tag=it->tag;
			t.split(rrt,lrt,1,n,r-itl+1,tag);
			st.erase(it);
			st.insert(node(r+1,itr,rrt,tag));
			st.insert(node(itl,r,lrt,tag));
		}		
		int rt=0;
		while(true)
		{
			it=st.lower_bound(node(0,l,0));
			if(it==st.end()||r<it->l) break;
			t.merge(rt,it->rt,1,n);
			st.erase(it);
		}
		st.insert(node(l,r,rt,o));
	}
	scanf("%d",&x);
	it=st.lower_bound(node(0,x,0));
	printf("%d",t.getkth(it->rt,1,n,it->tag?it->r-x+1:x-it->l+1));
}