#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int maxn=1e3+5;
int cost[10],m[10],city[10][maxn],dx[maxn],dy[maxn],f[maxn];
struct edge
{
	int u,v,w;
	edge(int u=0,int v=0,int w=0):u(u),v(v),w(w){}
}e[maxn*maxn],ex[maxn];
bool operator <(const edge& x,const edge& y)
{	return x.w<y.w; }
int getdist(int x,int y)
{	return pow(dx[x]-dx[y],2)+pow(dy[x]-dy[y],2); } 
int find(int x)
{	return x==f[x]?x:f[x]=find(f[x]); }
int kruskal(int n)
{
	int ans=0;
	for(int i=0;i<n-1;i++)
	{
		int fu=find(ex[i].u),fv=find(ex[i].v);
		if(fu==fv) continue;
		f[fu]=fv,ans+=ex[i].w;
	}
	return ans;
}
int main()
{
	int t,n,q,first=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&q);
		for(int i=1;i<=q;i++)
		{
			scanf("%d%d",&m[i],&cost[i]);
			for(int j=0;j<m[i];j++)
				scanf("%d",&city[i][j]);
		}
		for(int i=1;i<=n;i++)
			scanf("%d%d",&dx[i],&dy[i]),f[i]=i;
		int cnt=0,ans=0,tot=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				e[cnt++]=edge(i,j,getdist(i,j));
		sort(e,e+cnt);
		for(int i=0;i<cnt;i++)
		{
			int fu=find(e[i].u),fv=find(e[i].v);
			if(fu==fv) continue;
			f[fu]=fv,ans+=e[i].w,ex[tot++]=e[i];
		}
		for(int i=1;i<(1<<q);i++)
		{
			int c=0;
			for(int j=1;j<=n;j++) f[j]=j;
			for(int j=1;j<=q;j++)
				if(i&(1<<(j-1))) 
				{
					for(int k=1;k<m[j];k++)
						f[find(city[j][k-1])]=find(city[j][k]);
					c+=cost[j];
				}
			ans=min(ans,c+kruskal(n));
		}
		if(first++) puts("");
		printf("%d\n",ans);
	}
}