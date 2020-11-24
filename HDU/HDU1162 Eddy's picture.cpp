#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int maxn=105;
struct edge
{
	int u,v;
	double w;
	edge(int u=0,int v=0,double w=0):u(u),v(v),w(w){}
}e[maxn*maxn];
bool operator <(const edge& a,const edge& b)
{	return a.w<b.w; }
double x[maxn],y[maxn];
int tot,f[maxn];
double sqr(double a)
{	return a*a; }
double dist(int a,int b)
{	return sqrt(sqr(x[a]-x[b])+sqr(y[a]-y[b])); }
int find(int x)
{	return f[x]==x?x:f[x]=find(f[x]); }
double kruskal(int m)
{
	sort(e+1,e+m+1);
	double ans=0;
	for(int i=1;i<=m;i++)
	{
		int fu=find(e[i].u),fv=find(e[i].v);
		if(fu==fv) continue;
		f[fu]=fv,ans+=e[i].w;
	}
	return ans;
}
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		tot=0;
		for(int i=1;i<=n;i++)
		{
			f[i]=i;
			scanf("%lf%lf",&x[i],&y[i]);
			for(int j=1;j<i;j++)
				e[++tot]=edge(i,j,dist(i,j));
		}
		printf("%.2lf\n",kruskal(tot));
	}
}