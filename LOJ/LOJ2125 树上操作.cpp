#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
ll w[maxn],a;
vector<int>e[maxn];
int fat[maxn],dep[maxn],son[maxn],siz[maxn];
int top[maxn],nid[maxn],tid[maxn],idx;
void dfs1(int u,int f,int d)
{
	fat[u]=f,dep[u]=d,siz[u]=1;
	int hsiz=-1;
	for(int i=0;i<(int)e[u].size();i++)
	{
		int v=e[u][i];
		if(v==f) continue;
		dfs1(v,u,d+1);
		siz[u]+=siz[v];
		if(siz[v]>hsiz) son[u]=v,hsiz=siz[v];
	}
}
void dfs2(int u,int tp)
{
	tid[++idx]=u,nid[u]=idx,top[u]=tp;
	if(son[u]) dfs2(son[u],tp);
	for(int i=0;i<(int)e[u].size();i++)
	{
		int v=e[u][i];
		if(v==fat[u]||v==son[u]) continue;
		dfs2(v,v);
	}
}
struct node
{	ll sum,tag; }t[maxn<<2]; 
void push_up(int rt)
{	t[rt].sum=t[rt<<1].sum+t[rt<<1|1].sum; }
void push_down(int rt,int l,int r)
{
	ll tag=t[rt].tag; t[rt].tag=0;
	int lson=rt<<1,rson=lson|1,mid=(l+r)>>1; 
	if(tag)
	{
		t[lson].sum+=tag*(mid-l+1);
		t[rson].sum+=tag*(r-mid);
		t[lson].tag+=tag;
		t[rson].tag+=tag;
	}
}
void build(int rt,int l,int r)
{
	if(l==r) { t[rt].sum=w[tid[l]]; return; }
	int lson=rt<<1,rson=lson|1,mid=(l+r)>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
	push_up(rt);
}
void update(int rt,int L,int R,int l,int r,ll val)
{
	t[rt].sum+=val*(min(r,R)-max(l,L)+1);
	if(L<=l&&r<=R) { t[rt].tag+=val; return; }
	push_down(rt,l,r);
	int lson=rt<<1,rson=lson|1,mid=(l+r)>>1;
	if(L<=mid) update(lson,L,R,l,mid,val);
	if(R>mid) update(rson,L,R,mid+1,r,val);
	push_up(rt);
}
ll query(int rt,int L,int R,int l,int r)
{
	if(L<=l&&r<=R) return t[rt].sum;
	push_down(rt,l,r);
	int lson=rt<<1,rson=lson|1,mid=(l+r)>>1;
	ll ans=0;
	if(L<=mid) ans+=query(lson,L,R,l,mid);
	if(R>mid) ans+=query(rson,L,R,mid+1,r);
	return ans;
} 
ll querytort(int n,int x,int rt)
{
	ll ans=0;
	while(top[x]!=rt)
	{
		ans+=query(1,nid[top[x]],nid[x],1,n);
		x=fat[top[x]];
	}
	return ans+query(1,nid[rt],nid[x],1,n); 
}
int main()
{
	int n,m,u,v,o,x;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&w[i]);
	for(int i=1;i<n;i++)
		scanf("%d%d",&u,&v),e[u].push_back(v),e[v].push_back(u);
	dfs1(1,0,0);
	dfs2(1,1);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&o,&x);
		if(o==1) scanf("%lld",&a),update(1,nid[x],nid[x],1,n,a);
		if(o==2) scanf("%lld",&a),update(1,nid[x],nid[x]+siz[x]-1,1,n,a);
		if(o==3) printf("%lld\n",querytort(n,x,1));
	}
}