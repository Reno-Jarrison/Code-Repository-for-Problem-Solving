#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
#include<iostream>
using namespace std;
const int maxn=1e3+5;
int f[maxn];
double dx[maxn],dy[maxn];
struct edge
{
	int u,v; double w;
	edge(int u,int v,double w):u(u),v(v),w(w){}
};
vector<edge>e;
vector<edge>::iterator it;
bool operator <(const edge& x,const edge& y)
{	return x.w<y.w; }
double getdist(int x,int y)
{	return sqrt(pow((dx[x]-dx[y]),2)+pow((dy[x]-dy[y]),2)); }
int find(int x)
{	return f[x]==x?x:f[x]=find(f[x]); }
double kruskal()
{
	sort(e.begin(),e.end());
	double ans=0;
	for(it=e.begin();it!=e.end();it++)
	{
		edge tmp=*it;
		int fu=find(tmp.u),fv=find(tmp.v);
		if(fu==fv) continue;
		f[fu]=fv,ans+=tmp.w;
	}
	return ans;
}
int main()
{
	int n,m,u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lf%lf",&dx[i],&dy[i]),f[i]=i;
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		e.push_back(edge(u,v,0.0));
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			e.push_back(edge(i,j,getdist(i,j)));
	printf("%.2lf",kruskal());
}