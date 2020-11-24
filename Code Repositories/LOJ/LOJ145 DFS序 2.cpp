#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5;
ll w[maxn],x;
vector<int>e[maxn];
int idx,in[maxn],out[maxn],stamp[maxn];
struct node
{	ll sum,tag; }t[maxn<<1];
void dfs(int u,int fat)
{
	stamp[++idx]=u;
	in[u]=idx;
	for(int i=0;i<(int)e[u].size();i++)
	{
		int v=e[u][i];
		if(v!=fat) dfs(v,u);
	}
	out[u]=idx;
}
void push_up(int rt)
{	t[rt].sum=t[rt<<1].sum+t[rt<<1|1].sum; }
void push_down(int rt,int l,int r)
{
	int lson=rt<<1,rson=lson|1,mid=(l+r)>>1; 
	ll tag=t[rt].tag;
	t[lson].sum+=tag*(mid-l+1);
	t[lson].tag+=tag;
	t[rson].sum+=tag*(r-mid);
	t[rson].tag+=tag; 
	t[rt].tag=0;
}
void build(int rt,int l,int r)
{
	if(l==r) { t[rt].sum=w[stamp[l]]; return; }
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
	ll ans=0;
	int lson=rt<<1,rson=lson|1,mid=(l+r)>>1;
	if(L<=mid) ans+=query(lson,L,R,l,mid);
	if(R>mid) ans+=query(rson,L,R,mid+1,r);
	return ans;
}
int main()
{
	int n,m,r,u,v,o,a;
	scanf("%d%d%d",&n,&m,&r);
	for(int i=1;i<=n;i++)
		scanf("%lld",&w[i]);
	for(int i=1;i<n;i++)
		scanf("%d%d",&u,&v),e[u].push_back(v),e[v].push_back(u); 
	dfs(r,0);
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&o,&a);
		if(o==1) scanf("%lld",&x),update(1,in[a],out[a],1,n,x);
		else printf("%lld\n",query(1,in[a],out[a],1,n));
	}
}