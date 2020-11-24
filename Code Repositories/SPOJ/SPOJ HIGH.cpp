#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=15;
const double eps=1e-8;
double mat[maxn][maxn];
ll matrixtree(int n)
{
	for(int i=1;i<n;i++)
	{
		int pt=i;
		for(int j=i+1;j<n;j++)
			if(fabs(mat[j][i])>fabs(mat[pt][i])) pt=j;
		if(fabs(mat[pt][i])<eps) return 0;
		if(i!=pt) swap(mat[i],mat[pt]);
		for(int j=i+1;j<n;j++)
		{
			double p=mat[j][i]/mat[i][i];
			for(int k=i;k<n;k++)
				mat[j][k]-=mat[i][k]*p;
		}
	}
	double ans=1;
	for(int i=1;i<n;i++) ans*=mat[i][i];
	return (ll)(ans+0.5);
}
int main()
{
	int t,n,m,u,v;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(mat,0,sizeof(mat));
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&u,&v);
			mat[u][u]++,mat[v][v]++;
			mat[u][v]--,mat[v][u]--;			
		}
		printf("%lld\n",matrixtree(n));
	}
}