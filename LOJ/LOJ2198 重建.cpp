#include<bits/stdc++.h>
using namespace std;
const int maxn=55;
const double eps=1e-8;
double mat[maxn][maxn],w;
void link(int u,int v,double x)
{	mat[u][u]+=x,mat[v][v]+=x,mat[u][v]-=x,mat[v][u]-=x; }
double matrixtree(int n)
{
	for(int i=1;i<=n;i++)
	{
		int pt=i;
		for(int j=i+1;j<=n;j++)
			if(fabs(mat[j][i])>fabs(mat[pt][i])) pt=j;
		if(fabs(mat[pt][i])<eps) return 0;
		if(pt!=i) swap(mat[i],mat[pt]);
		for(int j=i+1;j<=n;j++)
		{
			double p=mat[j][i]/mat[i][i];
			for(int k=i;k<=n;k++)
				mat[j][k]-=mat[i][k]*p;
		}
	}
	double ans=1;
	for(int i=1;i<=n;i++) ans*=mat[i][i];
	return ans;
}
int main()
{
	int n;
	scanf("%d",&n);
	double mul=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		{
			scanf("%lf",&w);
			if(i>=j) continue;
			w=max(w,eps),w=min(w,1-eps);
			link(i,j,w/(1-w)),mul*=(1-w);
		}
	printf("%.8lf\n",matrixtree(n-1)*mul);
}