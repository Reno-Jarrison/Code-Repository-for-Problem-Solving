#include<cstdio>
#include<vector>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
const int maxn=1e6+5;
const ll inf=1LL<<62;
struct edge
{
	int from,to,nxt; ll w;
	edge(int from=0,int to=0,int nxt=0,ll w=0):
		from(from),to(to),nxt(nxt),w(w){}
}e[maxn*3],ex[maxn<<1];
int head[maxn],cnt,f[maxn],flag[maxn],root;
int lg2[maxn]={-1},dep[maxn],fat[maxn][20];
ll maxd[maxn][20],smaxd[maxn][20],delta,ans,tmp=inf;
void init()
{	memset(head,-1,sizeof(head)),cnt=0; }
void link(int u,int v,ll w)
{	ex[cnt]=edge(u,v,head[u],w),head[u]=cnt++; }
bool operator <(const edge& x,const edge& y)
{	return x.w<y.w; }
int find(int x)
{	return x==f[x]?x:f[x]=find(f[x]); }
ll kruskal(int n,int m)
{
	ll sum=0; sort(e+1,e+m+1);
	for(int i=1;i<=n;i++) f[i]=i;
	for(int i=1;i<=m;i++)
	{
		int u=e[i].from,v=e[i].to,fu=find(u),fv=find(v);
		if(fu==fv) continue;
		f[fu]=fv,sum+=e[i].w,flag[i]=1,root=u;
		link(u,v,e[i].w),link(v,u,e[i].w);
	}
	return sum;
}
void getlg2()
{	for(int i=1;i<=maxn-5;i++) lg2[i]=lg2[i>>1]+1; }
void dfs(int u,int f)
{
	dep[u]=dep[f]+1,fat[u][0]=f;
	for(int i=1;(1<<i)<=dep[u];i++)
	{
		int nxt=fat[u][i-1]; 
		ll m1=maxd[u][i-1],m2=maxd[nxt][i-1];
		ll sm1=smaxd[u][i-1],sm2=smaxd[nxt][i-1];
		fat[u][i]=fat[nxt][i-1],maxd[u][i]=max(m1,m2);
		if(m1==m2) smaxd[u][i]=max(sm1,sm2);
		else smaxd[u][i]=max(min(m1,m2),max(sm1,sm2));
	}
	for(int i=head[u];~i;i=ex[i].nxt)
	{
		int v=ex[i].to;
		if(v!=f) maxd[v][0]=ex[i].w,smaxd[v][0]=-1,dfs(v,u);
	}
}
void update(int x,int step,ll& mxd,ll& smxd)
{
	ll tmxd=maxd[x][step],tsmxd=smaxd[x][step];
	if(mxd==tmxd) smxd=max(smxd,tsmxd);
	else smxd=max(min(mxd,tmxd),max(smxd,tsmxd));
	mxd=max(mxd,tmxd);
}
void getans(int x,int y,ll& mxd,ll& smxd)
{
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y])
	{
		int step=lg2[dep[x]-dep[y]];
		update(x,step,mxd,smxd),x=fat[x][step];
	}
	if(x==y) return; 
	for(int i=lg2[dep[x]];i>=0;i--)
		if(fat[x][i]!=fat[y][i])
		{
			update(x,i,mxd,smxd),x=fat[x][i];
			update(y,i,mxd,smxd),y=fat[y][i];
		}
	update(x,0,mxd,smxd),update(y,0,mxd,smxd);
}
ll query(int id)
{
	int x=e[id].from,y=e[id].to;
	ll w=e[id].w,mxd=-1,smxd=-1;
	getans(x,y,mxd,smxd);
	if(w>mxd) return w-mxd;
	if(smxd==-1) return inf;
	return w-smxd;
}
int main()
{
	getlg2(),init();
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%lld",&x,&y,&delta),e[i]=edge(x,y,-1,delta);
	ans=kruskal(n,m),dfs(root,0);
	for(int i=1;i<=m;i++)
		if(!flag[i]) tmp=min(tmp,query(i));
	printf("%lld",ans+tmp);
}