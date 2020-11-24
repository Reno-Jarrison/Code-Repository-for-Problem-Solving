#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=3e5+5;
int lg2[maxn]={-1},fat[maxn][20],dep[maxn],a[maxn];
ll dis[maxn][20],tim1[maxn],tim2[maxn];
bool vis[maxn],tag[maxn];
struct edge
{
	int to,w,nxt;
	edge(int to=0,int w=0,int nxt=0):to(to),w(w),nxt(nxt){}
}e[maxn<<1];
int tot,head[maxn];
void link(int u,int v,int w)
{	e[++tot]=edge(v,w,head[u]),head[u]=tot;	}
void getlg2()
{	for(int i=1;i<=maxn-5;i++) lg2[i]=lg2[i>>1]+1; }
void dfs1(int u,int f)
{
	fat[u][0]=f,dep[u]=dep[f]+1;
	for(int i=1;(1<<i)<=dep[u];i++)
	{
		fat[u][i]=fat[fat[u][i-1]][i-1];
		dis[u][i]=dis[u][i-1]+dis[fat[u][i-1]][i-1];
	}
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==f) continue;
		dis[v][0]=e[i].w,dfs1(v,u);
	}
}
bool dfs2(int u)
{
	bool flag=false;
	if(vis[u]) return true;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(dep[v]<dep[u]) continue;
		flag=true;
		if(!dfs2(v)) return false;
	}
	return flag;
}
struct node
{
	int id; ll res;
	node(int id=0,ll res=0):id(id),res(res){}
}b[maxn];
bool operator <(const node& x,const node& y)
{	return x.res<y.res; }
bool check(ll t,int m)
{
	int cnt=0,cnt1=0,cnt2=0;
	memset(vis,0,sizeof(vis));
	memset(tag,0,sizeof(tag));
	for(int i=1;i<=m;i++)
	{
		int x=a[i]; ll tmp=0;
		for(int j=lg2[dep[x]];j>=0;j--)
			if(fat[x][j]>1&&tmp+dis[x][j]<=t)
				tmp+=dis[x][j],x=fat[x][j];
		tmp+=dis[x][0];
		if(fat[x][0]==1&&tmp<=t) 
			b[++cnt]=node(x,t-tmp);
		else vis[x]=true;
	}
	for(int i=head[1];i;i=e[i].nxt)
		if(!dfs2(e[i].to)) tag[e[i].to]=true;
	sort(b+1,b+cnt+1);
	for(int i=1;i<=cnt;i++)
		if(tag[b[i].id]&&b[i].res<dis[b[i].id][0])
			tag[b[i].id]=false;
		else tim1[++cnt1]=b[i].res;
	for(int i=head[1];i;i=e[i].nxt)
		if(tag[e[i].to])
			tim2[++cnt2]=dis[e[i].to][0];
	if(cnt1<cnt2) return false;
	sort(tim2+1,tim2+cnt2+1);
	int pt1=1,pt2=1;
	while(pt1<=cnt1&&pt2<=cnt2)
	{
		if(tim1[pt1]>=tim2[pt2]) pt2++;
		pt1++;
	}
	return pt2>cnt2;
}
int qr()
{
	int x=0; bool neg=false; char c=0;
	while(c<'0'||c>'9')
		neg|=c=='-',c=getchar();
	while(c>='0'&&c<='9')
		(x*=10)+=c-'0',c=getchar();
	return neg?-x:x;
}
void qw(ll x)
{
	x<0?putchar('-'),x=-x:false;
	if(x>9) qw(x/10);
	putchar(x%10+'0');
}
int main()
{
	int n=qr(),m,u,v,w,siz=0;
	ll l=0,r=0,mid;
	getlg2();
	for(int i=1;i<n;i++)
	{
		u=qr(),v=qr(),w=qr();
		link(u,v,w),link(v,u,w),r+=w;
		if(u==1||v==1) siz++;
	}
	m=qr();
	for(int i=1;i<=m;i++) a[i]=qr();
	if(siz>m) {	qw(-1); return 0; }
	dfs1(1,0);
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(check(mid,m)) r=mid-1;
		else l=mid+1;
	}
	qw(l);
}