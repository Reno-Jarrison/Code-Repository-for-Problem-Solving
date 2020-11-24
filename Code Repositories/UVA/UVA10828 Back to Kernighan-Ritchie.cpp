#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const double eps=1e-6;
vector<int>e[105];
int otd[105];
double mat[105][105];
bool inf[105];
void jordan(int n)
{
	for(int i=1;i<=n;i++)
	{
		int pt=i;
		for(int j=i+1;j<=n;j++)
			if(fabs(mat[j][i])>fabs(mat[pt][i])) pt=j;
		if(fabs(mat[pt][i])<eps) continue;
		if(i!=pt) swap(mat[i],mat[pt]);
		for(int j=0;j<=n;j++) if(j!=i)
			for(int k=n+1;k>=i;k--)
				mat[j][k]-=mat[j][i]/mat[i][i]*mat[i][k];
	}
	for(int i=1;i<=n;i++)
		if(fabs(mat[i][i])>eps)
			mat[i][n+1]/=mat[i][i];
}
int main()
{
	int n,u,v,x,q,cases=0;
	while(~scanf("%d",&n)&&n)
	{
		memset(mat,0,sizeof(mat));
		memset(otd,0,sizeof(otd));
		memset(inf,0,sizeof(inf));
		for(int i=1;i<=n;i++) e[i].clear();
		while(scanf("%d%d",&u,&v)&&u&&v)
			e[v].push_back(u),otd[u]++;
		mat[1][n+1]=-1;
		for(int i=1;i<=n;i++)
		{
			mat[i][i]=-1;
			int siz=e[i].size();
			for(int j=0;j<siz;j++)
			{
				int v=e[i][j];
				mat[i][v]+=1.0/otd[v];
			}
		}
		jordan(n);
		for(int i=n;i;i--)
		{
			if(fabs(mat[i][i])<eps&&fabs(mat[i][n+1])>eps) 
			{	inf[i]=true; continue; }
			for(int j=i+1;j<=n;j++)
				if(inf[j]&&fabs(mat[i][j])>eps)
			{	inf[i]=true; break; }
		}
		scanf("%d",&q);
		printf("Case #%d:\n",++cases);
		while(q--)
		{
			scanf("%d",&x);
			if(inf[x]) puts("infinity");
			else printf("%.3lf\n",fabs(mat[x][n+1])<eps?0.0:mat[x][n+1]);
		}
	}	
}