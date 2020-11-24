#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=3e5+5;
int a[maxn],ans[maxn];
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
{	int tag; }t[maxn<<2]; 
void push_down(int rt)
{
	t[rt<<1].tag+=t[rt].tag;
	t[rt<<1|1].tag+=t[rt].tag;
	t[rt].tag=0;
}
void update(int rt,int L,int R,int l,int r)
{
	if(L<=l&&r<=R) { t[rt].tag++; return; }
	push_down(rt);
	int lson=rt<<1,rson=lson|1,mid=(l+r)>>1;
	if(L<=mid) update(lson,L,R,l,mid);
	if(R>mid) update(rson,L,R,mid+1,r);
}
void query(int rt,int l,int r)
{
	if(l==r) { ans[tid[l]]=t[rt].tag; return; }
	push_down(rt);
	int lson=rt<<1,rson=lson|1,mid=(l+r)>>1;
	query(lson,l,mid);
	query(rson,mid+1,r);
}
void updatepath(int n,int x,int y)
{
	int end=y;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		if(x==end)
		{	if(x!=top[x]) update(1,nid[top[x]],nid[fat[x]],1,n); }
		else update(1,nid[top[x]],nid[x],1,n);
		x=fat[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	if(x==end)
	{	if(x!=y) update(1,nid[son[x]],nid[y],1,n); }
	else if(y==end)
	{	if(x!=y) update(1,nid[x],nid[fat[y]],1,n); }
	else update(1,nid[x],nid[y],1,n);
}
int main()
{
	int n,x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
		scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
	dfs1(a[1],0,0);
	dfs2(a[1],a[1]);
	for(int i=1;i<n;i++)
		updatepath(n,a[i],a[i+1]);
	query(1,1,n);
	for(int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
}