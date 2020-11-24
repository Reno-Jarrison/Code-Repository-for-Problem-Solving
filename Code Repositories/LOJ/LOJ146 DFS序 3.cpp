#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
#define lowbit(x) (x&(-x))
using namespace std;
const int maxn=1e6+5;
struct edge
{
	int to,nxt;
	edge(int to=0,int nxt=0):to(to),nxt(nxt){}
}e[maxn<<1];
int head[maxn],nxt[maxn],cnt;
int idx,in[maxn],out[maxn],dep[maxn],fat[maxn][20],lg2[maxn]={-1};
ll w[maxn],tree1[maxn],tree2[maxn],delta;
ll qr()
{
	ll tmp=0; bool neg=false;
	char c=getchar();
	while(c<'0'||c>'9') neg|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')
		tmp=(tmp<<3)+(tmp<<1)+(c^'0'),c=getchar();
	return neg?-tmp:tmp;
}
void qw(ll x)
{
	if(x<0) putchar('-'),x=-x;
	if(x>9) qw(x/10);
	putchar(x%10+'0');
}
void addedge(int u,int v)
{	e[cnt]=edge(v,head[u]),head[u]=cnt++; }
void getlg2()
{	for(int i=1;i<=maxn-5;i++) lg2[i]=lg2[i>>1]+1; }
int getlca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y])
		x=fat[x][lg2[dep[x]-dep[y]]];
	if(x==y) return x;
	for(int i=lg2[dep[x]];i>=0;i--)
		if(fat[x][i]^fat[y][i])
			x=fat[x][i],y=fat[y][i];
	return fat[x][0];
}
void dfs(int u,int f)
{
	in[u]=++idx,dep[u]=dep[f]+1,fat[u][0]=f;
	for(int i=1;(1<<i)<=dep[u];i++)
		fat[u][i]=fat[fat[u][i-1]][i-1];
	for(int i=head[u];~i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v!=f) dfs(v,u);
	}
	out[u]=idx;
}
void update(int x,ll val,int d,int n)
{	
	if(x==0) return;
	for(int i=x;i<=n;i+=lowbit(i))
		tree1[i]+=val,tree2[i]+=val*d;
}
ll query(int x,int d,int flag)
{
	ll ans=0;
	for(int i=x;i;i-=lowbit(i))
		if(flag==1) ans+=tree1[i];
		else if(flag==2) ans+=tree2[i]-tree1[i]*(d-1);
	return ans;
}
void update_path(int x,int y,ll val,int n)
{
	int lca=getlca(x,y),flca=fat[lca][0];
	update(in[x],val,dep[x],n),update(in[y],val,dep[y],n);
	update(in[lca],-val,dep[lca],n),update(in[flca],-val,dep[flca],n);
}
ll query_node(int x)
{	return query(out[x],dep[x],1)-query(in[x]-1,dep[x],1); }
ll query_tree(int x)
{	return query(out[x],dep[x],2)-query(in[x]-1,dep[x],2); }
int main()
{
	getlg2();
	memset(head,-1,sizeof(head));
	int n=qr(),m=qr(),rt=qr(),u,v,o;
	for(int i=1;i<=n;i++) w[i]=qr();
	for(int i=1;i<n;i++)
		u=qr(),v=qr(),addedge(u,v),addedge(v,u);
	dfs(rt,0);
	for(int i=1;i<=n;i++) update_path(i,i,w[i],n);
	for(int i=1;i<=m;i++)
	{
		o=qr();
		if(o==1) u=qr(),v=qr(),delta=qr(),update_path(u,v,delta,n);
		if(o==2) u=qr(),qw(query_node(u)),puts("");
		if(o==3) u=qr(),qw(query_tree(u)),puts("");
	}
}