#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int w[maxn];
vector<int>e[maxn];
int fat[maxn],dep[maxn],siz[maxn],son[maxn];
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
{	int num,lc,rc,tag; }t[maxn<<2];
void modify(int rt,int c)
{	t[rt].num=1,t[rt].tag=t[rt].lc=t[rt].rc=c; }
void push_up(int rt)
{
	int lson=rt<<1,rson=lson|1;
	t[rt].num=t[lson].num+t[rson].num-(t[lson].rc==t[rson].lc);
	t[rt].lc=t[lson].lc,t[rt].rc=t[rson].rc;
	t[rt].tag=-1;
}
void push_down(int rt)
{
	int lson=rt<<1,rson=lson|1,tag=t[rt].tag; 
	if(tag>=0) modify(lson,tag),modify(rson,tag);
	t[rt].tag=-1;
}
void build(int rt,int l,int r)
{
	if(l==r) { modify(rt,w[tid[l]]),t[rt].tag=-1; return; }
	int lson=rt<<1,rson=lson|1,mid=(l+r)>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
	push_up(rt);
} 
void update(int rt,int L,int R,int l,int r,int c)
{
	if(L<=l&&r<=R) { modify(rt,c); return; }
	push_down(rt); 
	int lson=rt<<1,rson=lson|1,mid=(l+r)>>1;
	if(L<=mid) update(lson,L,R,l,mid,c);
	if(R>mid) update(rson,L,R,mid+1,r,c);
	push_up(rt); 
}
int query(int rt,int L,int R,int l,int r,int& lans,int& rans)
{
	if(l==L) lans=t[rt].lc;
	if(r==R) rans=t[rt].rc;
	if(L<=l&&r<=R) return t[rt].num;
	push_down(rt);
	int lson=rt<<1,rson=lson|1,mid=(l+r)>>1;
	ll ans=0;
	if(L<=mid) ans+=query(lson,L,R,l,mid,lans,rans);
	if(R>mid) ans+=query(rson,L,R,mid+1,r,lans,rans);
	if(L<=mid&&mid<R) ans-=(t[lson].rc==t[rson].lc);
	return ans;
}
void updatepath(int n,int x,int y,int c)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		update(1,nid[top[x]],nid[x],1,n,c);
		x=fat[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	update(1,nid[x],nid[y],1,n,c);
}
int querypath(int n,int x,int y)
{
	int ans=0,ans1=-1,ans2=-1,lans,rans;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y),swap(ans1,ans2);
		ans+=query(1,nid[top[x]],nid[x],1,n,lans,rans);
		rans==ans1?ans--:0,ans1=lans;
		x=fat[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y),swap(ans1,ans2);
	return ans+query(1,nid[x],nid[y],1,n,lans,rans)-(lans==ans1)-(rans==ans2);
}
int main()
{
	int n,m,x,y,a,b,c;
	char cmd[3];
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&w[i]);
	for(int i=1;i<n;i++)
		scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
	dfs1(1,0,0);
	dfs2(1,1);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		scanf("%s%d%d",cmd,&a,&b); 
		if(cmd[0]=='C') scanf("%d",&c),updatepath(n,a,b,c);
		if(cmd[0]=='Q') printf("%d\n",querypath(n,a,b));
	}
}