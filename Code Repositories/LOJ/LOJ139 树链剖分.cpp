#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
ll w[maxn],z;
vector<int>e[maxn];
int siz[maxn],dep[maxn],fat[maxn],son[maxn];
int top[maxn],nid[maxn],tid[maxn],idx,root=1;
void dfs1(int u,int f,int d)
{
	siz[u]=1,fat[u]=f,dep[u]=d;
	int hsiz=-1;
	for(int i=0;i<(int)e[u].size();i++)
	{
		int v=e[u][i];
		if(v==f) continue;
		dfs1(v,u,d+1);
		siz[u]+=siz[v];
		if(siz[v]>hsiz) 
			son[u]=v,hsiz=siz[v];
	}
}
void dfs2(int u,int tp)
{
	nid[u]=++idx,tid[idx]=u,top[u]=tp;
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
	ll tag=t[rt].tag;
	int lson=rt<<1,rson=lson|1,mid=(l+r)>>1;
	t[lson].sum+=tag*(mid-l+1);
	t[rson].sum+=tag*(r-mid);
	t[lson].tag+=tag;
	t[rson].tag+=tag;
	t[rt].tag=0;
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
void updatepath(int n,int x,int y,ll val)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		update(1,nid[top[x]],nid[x],1,n,val);
		x=fat[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	update(1,nid[x],nid[y],1,n,val); 
}
ll querypath(int n,int x,int y)
{
	ll ans=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		ans+=query(1,nid[top[x]],nid[x],1,n);
		x=fat[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	return ans+query(1,nid[x],nid[y],1,n);
}
int getlca(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fat[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
int getson(int x,int y=root)
{
	while(top[x]!=top[y])
	{
		if(fat[top[y]]==x)
			return top[y];
		y=fat[top[y]];
	}
	return son[x];
}
void updateson(int n,int x,ll val)
{
	if(getlca(root,x)==x)
	{
		update(1,1,n,1,n,val);
		if(root!=x) 
		{	int s=getson(x); update(1,nid[s],nid[s]+siz[s]-1,1,n,-val); }
	}
	else update(1,nid[x],nid[x]+siz[x]-1,1,n,val); 
}
ll queryson(int n,int x)
{	
	if(getlca(root,x)==x)
	{
		ll ans=t[1].sum;
		if(root!=x) 
		{	int s=getson(x); ans-=query(1,nid[s],nid[s]+siz[s]-1,1,n); }
		return ans;
	}
	return query(1,nid[x],nid[x]+siz[x]-1,1,n); 
}
int main()
{
	int n,m,u,o,x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&w[i]);
	for(int i=2;i<=n;i++)
		scanf("%d",&u),e[u].push_back(i);
	dfs1(root,0,0);
	dfs2(root,root);
	build(1,1,n);
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&o,&x);
		if(o==1) root=x;
		if(o==2) scanf("%d%lld",&y,&z),updatepath(n,x,y,z);
		if(o==3) scanf("%lld",&z),updateson(n,x,z);
		if(o==4) scanf("%d",&y),printf("%lld\n",querypath(n,x,y)); 
		if(o==5) printf("%lld\n",queryson(n,x)); 
	}
}