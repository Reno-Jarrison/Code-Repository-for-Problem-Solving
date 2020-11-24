#include<cstdio>
#include<cmath>
#include<algorithm> 
using namespace std;
const int maxn=505; 
struct edge
{	
	int u,v; double w;
	edge(){} 
	edge(int u,int v,double w):u(u),v(v),w(w){}	
}e[maxn*maxn];
bool operator <(const edge& x,const edge& y)
{	return x.w<y.w; }
int nx[maxn],ny[maxn],f[maxn],ecnt;
int find(int x)
{	return f[x]==x?x:f[x]=find(f[x]); }
double kruskal(int m,int n)
{
	double ans=0;
	int cnt=0;
	for(int i=0;i<ecnt&&cnt<n-m;i++)
	{
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu^fv) f[fu]=fv,ans=e[i].w,cnt++;
	}
	return ans;
}
double sqr(int x) { return x*x; }
double dis(int u,int v)
{	return sqrt(sqr(nx[u]-nx[v])+sqr(ny[u]-ny[v])); }
int main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&n),ecnt=0;
		for(int i=1;i<=n;i++)
			scanf("%d%d",&nx[i],&ny[i]),f[i]=i;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				e[ecnt++]=edge(i,j,dis(i,j));
		sort(e,e+ecnt);
		printf("%.2lf\n",kruskal(m,n));
	}
}
