#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
ll w[maxn];
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
{	int sum,tag; }t[maxn<<2];
void push_up(int rt)
{	t[rt].sum=t[rt<<1].sum+t[rt<<1|1].sum; }
void push_down(int rt,int l,int r)
{
	int lson=rt<<1,rson=lson|1,mid=(l+r)>>1,tag=t[rt].tag; 
	if(tag)
	{
		if(tag>0) t[lson].sum=mid-l+1,t[rson].sum=r-mid;
		else t[lson].sum=t[rson].sum=0;
		t[lson].tag=t[rson].tag=tag;
	}
	t[rt].tag=0;
}
void update(int rt,int L,int R,int l,int r,int flag)
{
	if(L<=l&&r<=R) { t[rt].sum=flag>0?r-l+1:0,t[rt].tag=flag; return; }
	push_down(rt,l,r); 
	int lson=rt<<1,rson=lson|1,mid=(l+r)>>1;
	if(L<=mid) update(lson,L,R,l,mid,flag);
	if(R>mid) update(rson,L,R,mid+1,r,flag);
	push_up(rt); 
}
int query(int rt,int L,int R,int l,int r)
{
	if(L<=l&&r<=R) return t[rt].sum;
	push_down(rt,l,r);
	int lson=rt<<1,rson=lson|1,mid=(l+r)>>1;
	ll ans=0;
	if(L<=mid) ans+=query(lson,L,R,l,mid);
	if(R>mid) ans+=query(rson,L,R,mid+1,r);
	return ans;
}
int updatetort(int n,int x,int rt)
{
	int ans=0;
	while(top[x]!=rt)
	{
		ans+=nid[x]-nid[top[x]]+1;
		ans-=query(1,nid[top[x]],nid[x],1,n);
		update(1,nid[top[x]],nid[x],1,n,1);
		x=fat[top[x]];
	}
	ans+=nid[x]-nid[rt]-query(1,nid[rt],nid[x],1,n)+1;
	update(1,nid[rt],nid[x],1,n,1);
	return ans;
}
int updateson(int n,int x)
{
	int ans=query(1,nid[x],nid[x]+siz[x]-1,1,n);
	update(1,nid[x],nid[x]+siz[x]-1,1,n,-1);
	return ans; 
}
int main()
{
	int n,f,q,x;
	char cmd[15];
	scanf("%d",&n);
	for(int i=1;i<n;i++)
		scanf("%d",&f),e[f].push_back(i);
	dfs1(0,0,0);
	dfs2(0,0);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%s%d",cmd,&x); 
		if(cmd[0]=='i') printf("%d\n",updatetort(n,x,0));
		if(cmd[0]=='u') printf("%d\n",updateson(n,x));
	}
}