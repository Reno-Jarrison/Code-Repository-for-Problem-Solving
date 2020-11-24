#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int c[maxn]; ll w[maxn];
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
{	ll sum,maxm; int c,l,r; }t[maxn<<5];
int cnt,root[maxn];
void push_up(int rt)
{
	t[rt].maxm=max(t[t[rt].l].maxm,t[t[rt].r].maxm);
	t[rt].sum=t[t[rt].l].sum+t[t[rt].r].sum;
}
void update(int& rt,int pos,int l,int r,ll val)
{
	if(!rt) rt=++cnt;
	if(l==r) { t[rt].maxm=t[rt].sum=val; return; }
	int mid=(l+r)>>1;
	if(pos<=mid) update(t[rt].l,pos,l,mid,val);
	else update(t[rt].r,pos,mid+1,r,val);
	push_up(rt);
}
void del(int& rt,int pos,int l,int r)
{
	if(!rt) return;
	if(l==r) { t[rt].maxm=t[rt].sum=0; return; }
	int mid=(l+r)>>1;
	if(pos<=mid) del(t[rt].l,pos,l,mid);
	else del(t[rt].r,pos,mid+1,r);
	push_up(rt);
}
ll query(int rt,int L,int R,int l,int r,bool flag)
{
	if(!rt) return 0;
	if(L<=l&&r<=R) return flag?t[rt].maxm:t[rt].sum;
	ll ans=0,q; int mid=(l+r)>>1;
	if(L<=mid) q=query(t[rt].l,L,R,l,mid,flag),flag?ans=max(ans,q):ans+=q;
	if(R>mid) q=query(t[rt].r,L,R,mid+1,r,flag),flag?ans=max(ans,q):ans+=q; 
	return ans;
}
ll querypath(int n,int x,int y,bool flag)
{
	ll ans=0,q; int pt=c[x];
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		q=query(root[pt],nid[top[x]],nid[x],1,n,flag);
		flag?ans=max(ans,q):ans+=q;
		x=fat[top[x]];
	}
	if(dep[x]>dep[y]) swap(x,y);
	q=query(root[pt],nid[x],nid[y],1,n,flag);
	flag?ans=max(ans,q):ans+=q; 
	return ans;
}
int main()
{
	int n,q,x,y;
	char cmd[4];
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%lld%d",&w[i],&c[i]);
	for(int i=1;i<n;i++)
		scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
	dfs1(1,0,0);
	dfs2(1,1);
	for(int i=1;i<=n;i++)
		update(root[c[i]],nid[i],1,n,w[i]);
	for(int i=1;i<=q;i++)
	{
		scanf("%s%d%d",cmd,&x,&y);
		if(cmd[0]=='C') 
		{
			del(root[c[x]],nid[x],1,n);
			cmd[1]=='C'?c[x]=y:w[x]=y;
			update(root[c[x]],nid[x],1,n,w[x]);
		}
		if(cmd[0]=='Q')
			printf("%lld\n",querypath(n,x,y,cmd[1]=='M'));
	}
}