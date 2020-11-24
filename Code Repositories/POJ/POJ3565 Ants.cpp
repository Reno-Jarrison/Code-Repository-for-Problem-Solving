#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std; 
const int maxn=105;
const double eps=1e-10;
double w[maxn][maxn],lx[maxn],ly[maxn],slack[maxn];
int x[maxn][2],y[maxn][2],mat[maxn];
bool visx[maxn],visy[maxn];
double getdist(double a,double b)
{	return sqrt(a*a+b*b); }
int dcmp(double x)
{	return fabs(x)>eps; }
bool dfs(int u,int ny)
{
	visx[u]=true;
	for(int v=1;v<=ny;v++)
	{
		if(visy[v]) continue;
		double tmp=lx[u]+ly[v]-w[u][v];
		if(dcmp(tmp)) slack[v]=min(slack[v],tmp);
		else
		{
			visy[v]=true;
			if(!mat[v]||dfs(mat[v],ny))
			{	mat[v]=u; return true; }	
		}
	}
	return false;
}
void km(int nx,int ny)
{
	memset(mat,0,sizeof(mat));
	memset(lx,0,sizeof(lx));
	memset(ly,0,sizeof(ly));
	for(int i=1;i<=nx;i++)
		for(int j=1;j<=ny;j++)
			lx[i]=max(lx[i],w[i][j]);
	for(int i=1;i<=nx;i++)
	{	
		for(int j=1;j<=ny;j++)
			slack[j]=1e10;
		while(true)
		{
			memset(visx,0,sizeof(visx));
			memset(visy,0,sizeof(visy));
			if(dfs(i,ny)) break;
			double delta=1e10;
			for(int i=1;i<=ny;i++)
				if(!visy[i]&&delta>slack[i])
					delta=slack[i];
			for(int i=1;i<=nx;i++)
				if(visx[i]) lx[i]-=delta;
			for(int i=1;i<=ny;i++)
				visy[i]?ly[i]+=delta:slack[i]-=delta;
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i][0],&y[i][0]);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i][1],&y[i][1]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			w[j][i]=-getdist(x[i][0]-x[j][1],y[i][0]-y[j][1]);
	km(n,n);
	for(int i=1;i<=n;i++)
		printf("%d\n",mat[i]);
}