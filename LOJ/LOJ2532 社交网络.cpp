#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=255,mod=10007;
ll mat[maxn][maxn];
void link(int u,int v)
{	mat[u][u]++,mat[u][v]--; }
ll matrixtree(int n)
{
	ll ans=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
			while(mat[j][i])
			{
				ll p=mat[i][i]/mat[j][i];
				for(int k=i;k<=n;k++)
				{
					mat[i][k]=(mat[i][k]-mat[j][k]*p%mod+mod)%mod;
					swap(mat[i][k],mat[j][k]);
				}
				ans*=-1;
			}
		ans=(ans*mat[i][i]%mod+mod)%mod;
	}
	return ans;
}
int main()
{
	int n,m,u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&u,&v),link(u-1,v-1);
	printf("%lld\n",matrixtree(n-1));
}