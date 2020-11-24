#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
vector<int>e[maxn];
int siz[maxn],dfn[maxn],idx;
void link(int u,int v)
{	e[u].push_back(v),e[v].push_back(u); }
void dfs(int u,int f)
{
	siz[u]=1,dfn[u]=++idx;
	for(int i=0;i<(int)e[u].size();i++)
	{
		int v=e[u][i];
		if(v==f) continue;
		dfs(v,u),siz[u]+=siz[v];
	}
}
struct Segtree
{
	int tag[maxn<<2];
	void update(int rt,int l,int r,int L,int R,int val)
	{
		if(L<=l&&r<=R)
		{	if(dfn[val]>dfn[tag[rt]]) tag[rt]=val; return; }
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
		if(L<=mid) update(lson,l,mid,L,R,val);
		if(R>mid) update(rson,mid+1,r,L,R,val);
	}
	int query(int rt,int l,int r,int pos,int ans)
	{
		if(tag[rt]) ans=tag[rt];
		if(l==r) return ans;
		int mid=(l+r)>>1,lson=rt<<1,rson=lson|1;
		if(pos<=mid) return query(lson,l,mid,pos,ans);
		else return query(rson,mid+1,r,pos,ans);
	}
}t;
int main()
{
	int n,m,u,v;
	char o[3];
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
		scanf("%d%d",&u,&v),link(u,v);
	dfs(1,0);
	for(int i=1;i<=m;i++)
	{
		scanf("%s%d",o,&u);
		if(o[0]=='C') t.update(1,1,n,dfn[u],dfn[u]+siz[u]-1,u);
		if(o[0]=='Q') printf("%d\n",t.query(1,1,n,dfn[u],1));
	}
}