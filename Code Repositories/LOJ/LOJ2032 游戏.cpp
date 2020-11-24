#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
const ll inf=123456789123456789LL;
struct edge
{
	int to,w;
	edge(int to,int w):to(to),w(w){}
};
vector<edge>e[maxn];
void link(int u,int v,int w)
{	e[u].push_back(edge(v,w)),e[v].push_back(edge(u,w)); }
ll dis[maxn],k[maxn],b[maxn];
int siz[maxn],fat[maxn],dep[maxn],son[maxn],cnt;
void dfs1(int u,int f)
{
	siz[u]=1,fat[u]=f,dep[u]=dep[f]+1;
	for(int i=0;i<(int)e[u].size();i++)
	{
		int v=e[u][i].to,w=e[u][i].w;
		if(v==f) continue;
		dis[v]=dis[u]+w;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[v]>siz[son[u]]) son[u]=v;
	}
}
int top[maxn],dfn[maxn],vid[maxn],idx;
void dfs2(int u,int tp)
{
	top[u]=tp,dfn[u]=++idx,vid[idx]=u;
	if(son[u]) dfs2(son[u],tp);
	for(int i=0;i<(int)e[u].size();i++)
	{
		int v=e[u][i].to;
		if(v==fat[u]||v==son[u]) continue;
		dfs2(v,v);
	}
}
int getlca(int x,int y)
{
	while(top[x]!=top[y])
		dep[top[x]]>dep[top[y]]?x=fat[top[x]]:y=fat[top[y]];
	return dep[x]<dep[y]?x:y;
}
ll getval(int id,int x)
{	return k[id]*dis[vid[x]]+b[id]; }
struct Segtree
{
	int tot,tag[maxn<<2]; ll mnv[maxn<<2];
	void push_up(int rt,int lson,int rson)
	{	mnv[rt]=min(mnv[rt],min(mnv[lson],mnv[rson])); }
	void build(int rt,int l,int r)
	{
		mnv[rt]=inf;
		if(l==r) return;
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
		build(lson,l,mid),build(rson,mid+1,r);
	}
	void update(int rt,int l,int r,int L,int R,int id)
	{
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
		if(L<=l&&r<=R)
		{
			ll lcurval=getval(tag[rt],l),lnewval=getval(id,l);
			ll rcurval=getval(tag[rt],r),rnewval=getval(id,r);
			if(lnewval<=lcurval&&rnewval<=rcurval)
			{	tag[rt]=id,mnv[rt]=min(mnv[rt],min(lnewval,rnewval)); return; }
			if(lnewval>=lcurval&&rnewval>=rcurval) return;
			ll mcurval=getval(tag[rt],mid),mnewval=getval(id,mid);
			if(k[id]>k[tag[rt]])
			{
				if(mnewval>=mcurval) update(lson,l,mid,L,R,id);
				else update(rson,mid+1,r,L,R,tag[rt]),tag[rt]=id;
			}
			else
			{
				if(mnewval>=mcurval) update(rson,mid+1,r,L,R,id);
				else update(lson,l,mid,L,R,tag[rt]),tag[rt]=id;
			}
			mnv[rt]=min(mnv[rt],min(lnewval,rnewval));
			push_up(rt,lson,rson); return;
		}
		if(L<=mid) update(lson,l,mid,L,R,id);
		if(R>mid) update(rson,mid+1,r,L,R,id);
		push_up(rt,lson,rson);
	}
	ll query(int rt,int l,int r,int L,int R)
	{
		if(L<=l&&r<=R) return mnv[rt];
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
		ll ans=min(getval(tag[rt],max(l,L)),getval(tag[rt],min(r,R)));
		if(L<=mid) ans=min(ans,query(lson,l,mid,L,R));
		if(R>mid) ans=min(ans,query(rson,mid+1,r,L,R));
		return ans;
	}
	void update_path(int x,int y,int val)
	{
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			update(1,1,tot,dfn[top[x]],dfn[x],val);
			x=fat[top[x]];
		}
		if(dep[x]>dep[y]) swap(x,y);
		update(1,1,tot,dfn[x],dfn[y],val);
	}
	ll query_path(int x,int y)
	{
		ll ans=inf;
		while(top[x]!=top[y])
		{
			if(dep[top[x]]<dep[top[y]]) swap(x,y);
			ans=min(ans,query(1,1,tot,dfn[top[x]],dfn[x]));
			x=fat[top[x]];
		}
		if(dep[x]>dep[y]) swap(x,y);
		return min(ans,query(1,1,tot,dfn[x],dfn[y]));
	}
}t;
int main()
{
	int n,m,o,u,v,w;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
		scanf("%d%d%d",&u,&v,&w),link(u,v,w);
	dfs1(1,0),dfs2(1,1);
	k[0]=0,b[0]=inf;
	t.build(1,1,n),t.tot=n;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&o,&u,&v);
		if(o==2) printf("%lld\n",t.query_path(u,v));
		else
		{
			ll kx,bx;
			scanf("%lld%lld",&kx,&bx);
			int lca=getlca(u,v);
			k[++cnt]=-kx,b[cnt]=kx*dis[u]+bx;
			t.update_path(lca,u,cnt);
			k[++cnt]=kx,b[cnt]=kx*(dis[u]-dis[lca]*2)+bx;
			t.update_path(lca,v,cnt);
		}
	}
}