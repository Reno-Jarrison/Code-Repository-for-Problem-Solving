#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
#define lowbit(x) ((x)&(-x))
using namespace std;
const int maxn=1e6+5;
struct edge
{
	int to,nxt;
	edge(int to=0,int nxt=0):to(to),nxt(nxt){}
}e[maxn<<1];
int head[maxn],cnt;
void init()
{	memset(head,-1,sizeof(head)),cnt=0; }
void link(int u,int v)
{	e[cnt]=edge(v,head[u]),head[u]=cnt++; }
int idx,in[maxn],out[maxn],dep[maxn],fat[maxn][20],lg2[maxn]={-1};
ll tree1[maxn],tree2[maxn],w[maxn],delta;
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
void update(int x,ll val,int d,int flag,int n)
{
	if(x==0) return;
	for(int i=x;i<=n;i+=lowbit(i))
		if(flag==1) tree1[i]+=val;
		else if(flag==2) tree2[i]+=val*(d-1);
}
ll query(int x,int d)
{
	ll ans=0;
	for(int i=x;i;i-=lowbit(i))
		ans+=tree1[i]*d+tree2[i];
	return ans;
}
void update_node(int x,ll val,int n)
{	update(in[x],val,2,2,n),update(out[x]+1,-val,2,2,n); }
void update_tree(int x,ll val,int n)
{	
	update(in[x],val,0,1,n),update(out[x]+1,-val,0,1,n);
	update(in[x],-val,dep[x],2,n),update(out[x]+1,val,dep[x],2,n);
}
ll query_path(int x,int y)
{
	int lca=getlca(x,y),flca=fat[lca][0]; ll ans=0;
	ans+=query(in[x],dep[x])+query(in[y],dep[y]);
	ans-=query(in[lca],dep[lca])+query(in[flca],dep[flca]);
	return ans;
}
int main()
{
	init(),getlg2();
	int n=qr(),q=qr(),rt=qr(),o,x,y;
	for(int i=1;i<=n;i++) w[i]=qr();
	for(int i=1;i<n;i++)
		x=qr(),y=qr(),link(x,y),link(y,x);
	dfs(rt,0);
	for(int i=1;i<=n;i++) update_node(i,w[i],n);
	for(int i=1;i<=q;i++)
	{
		o=qr();
		if(o==1) x=qr(),delta=qr(),update_node(x,delta,n);
		if(o==2) x=qr(),delta=qr(),update_tree(x,delta,n);
		if(o==3) x=qr(),y=qr(),qw(query_path(x,y)),puts("");
	}
}