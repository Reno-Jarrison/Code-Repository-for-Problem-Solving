#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,maxm=5e5+5,inf=0x3f3f3f3f;
struct edge
{
	int u,v,w;
	edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
}e[maxm];
struct edgex
{
	int to,w;
	edgex(int to,int w):to(to),w(w){}
};
vector<edgex>ex[maxn];
int lg2[maxn]={-1},f[maxn],cnt;
int fat[maxn][20],dep[maxn],minw[maxn][20];
int find(int x)
{	return f[x]==x?x:f[x]=find(f[x]); }
bool operator <(const edge& x,const edge& y)
{	return x.w<y.w; }
void getlg2()
{	for(int i=1;i<=maxn-5;i++) lg2[i]=lg2[i>>1]+1; }
void dfs(int u,int fa)
{
	dep[u]=dep[fa]+1,fat[u][0]=fa;
	for(int i=1;(1<<i)<=dep[u];i++)
	{
		fat[u][i]=fat[fat[u][i-1]][i-1];
		minw[u][i]=min(minw[u][i-1],minw[fat[u][i-1]][i-1]);
	}
	for(int i=0;i<(int)ex[u].size();i++)
	{
		int v=ex[u][i].to,w=ex[u][i].w;
		if(v!=fa) minw[v][0]=w,dfs(v,u);
	}
}
int query(int x,int y)
{
	if(find(x)!=find(y)) return -1;
	int ans=inf;
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y])
	{
		int len=lg2[dep[x]-dep[y]];
		ans=min(ans,minw[x][len]);
		x=fat[x][len];
	}
	if(x==y) return ans;
	for(int i=lg2[dep[x]];i>=0;i--)
		if(fat[x][i]!=fat[y][i])
		{
			ans=min(ans,minw[x][i]);
			ans=min(ans,minw[y][i]);
			x=fat[x][i],y=fat[y][i];
		}
	ans=min(ans,minw[x][0]);
	ans=min(ans,minw[y][0]);
	return ans;
}
int main()
{
	int n,m,q,u,v,w;
	getlg2();
	memset(minw,inf,sizeof(minw));
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d",&u,&v,&w),e[++cnt]=edge(u,v,w);
	sort(e+1,e+cnt+1);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=cnt;i;i--)
	{
		u=e[i].u,v=e[i].v;
		int fu=find(u),fv=find(v);
		if(fu==fv) continue;
		f[fu]=fv;
		ex[u].push_back(edgex(v,e[i].w));
		ex[v].push_back(edgex(u,e[i].w));
	}
	for(int i=1;i<=n;i++) 
		if(!dep[i]) dfs(i,i);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
		scanf("%d%d",&u,&v),printf("%d\n",query(u,v));
}