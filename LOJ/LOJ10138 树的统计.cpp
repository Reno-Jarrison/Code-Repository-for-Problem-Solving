#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=3e4+5;
int w[maxn],inf=0x3f3f3f3f;
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
	top[u]=tp,nid[u]=++idx,tid[idx]=u;
	if(son[u]) dfs2(son[u],tp);
	for(int i=0;i<(int)e[u].size();i++)
	{
		int v=e[u][i];
		if(v==fat[u]||v==son[u]) continue;
		dfs2(v,v); 
	}
}
struct node
{	ll sum,maxm; }t[maxn<<2];
void push_up(int rt)
{
	t[rt].sum=t[rt<<1].sum+t[rt<<1|1].sum;
	t[rt].maxm=max(t[rt<<1].maxm,t[rt<<1|1].maxm);
}
void build(int rt,int l,int r)
{
	if(l==r) { t[rt].sum=t[rt].maxm=w[tid[l]]; return; }
	int lson=rt<<1,rson=lson|1,mid=(l+r)>>1;
	build(lson,l,mid);
	build(rson,mid+1,r);
	push_up(rt);
}
void update(int rt,int pos,int l,int r,int val)
{
	if(l==r) { t[rt].sum=t[rt].maxm=val; return; }
	int lson=rt<<1,rson=lson|1,mid=(l+r)>>1;
	if(pos<=mid) update(lson,pos,l,mid,val);
	else update(rson,pos,mid+1,r,val);
	push_up(rt);
}
int query(int rt,int L,int R,int l,int r,bool flag)
{
	if(L<=l&&r<=R) return flag?t[rt].maxm:t[rt].sum;
	int lson=rt<<1,rson=lson|1,mid=(l+r)>>1,ans=flag?-inf:0,q;
	if(L<=mid) q=query(lson,L,R,l,mid,flag),flag?ans=max(ans,q):ans+=q;
	if(R>mid) q=query(rson,L,R,mid+1,r,flag),flag?ans=max(ans,q):ans+=q;
	return ans; 
}
int querypath(int n,int u,int v,bool flag)
{
	int ans=flag?-inf:0,q;
	while(top[u]!=top[v])
	{
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		q=query(1,nid[top[u]],nid[u],1,n,flag);
		flag?ans=max(ans,q):ans+=q;
		u=fat[top[u]];
	}
	if(dep[u]>dep[v]) swap(u,v);
	q=query(1,nid[u],nid[v],1,n,flag);
	flag?ans=max(ans,q):ans+=q;
	return ans;
}
int main()
{
	int n,u,v,q,t;
	char cmd[10];
	scanf("%d",&n);
	for(int i=1;i<n;i++)
		scanf("%d%d",&u,&v),e[u].push_back(v),e[v].push_back(u);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	dfs1(1,0,0);
	dfs2(1,1);
	build(1,1,n); 
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%s%d",cmd,&u);
		if(cmd[0]=='C') 
			scanf("%d",&t),update(1,nid[u],1,n,t);
		else scanf("%d",&v),printf("%d\n",querypath(n,u,v,cmd[1]=='M'));
	}
}