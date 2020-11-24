#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn=1e3+5;
int g[maxn][maxn],f[maxn*maxn];
struct edge
{
	int u,v,w;
	edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
}e[maxn*maxn*2];
bool operator <(const edge& x,const edge& y)
{	return x.w<y.w; } 
int find(int x)
{	return x==f[x]?x:f[x]=find(f[x]); }
int main()
{
	int t,n,m,u,v,cases=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&g[i][j]),f[(i-1)*m+j]=(i-1)*m+j;
		int ans=0,cnt=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				u=(i-2)*m+j,v=(i-1)*m+j;
				if(i>1) e[++cnt]=edge(u,v,abs(g[i-1][j]-g[i][j]));
				u=(i-1)*m+j-1,v=(i-1)*m+j;
				if(j>1) e[++cnt]=edge(u,v,abs(g[i][j-1]-g[i][j]));
			}
		sort(e+1,e+cnt+1);
		for(int i=1;i<=cnt;i++)
		{
			edge tmp=e[i];
			int fu=find(tmp.u),fv=find(tmp.v);
			if(fu==fv) continue;
			f[fu]=fv,ans+=tmp.w; 
		}
		printf("Case #%d:\n%d\n",++cases,ans);
	}
}