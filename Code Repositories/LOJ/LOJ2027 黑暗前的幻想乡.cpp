#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=20,mod=1e9+7;
ll mat[maxn][maxn];
int m[maxn],eu[maxn][maxn*maxn],ev[maxn][maxn*maxn];
void link(int u,int v)
{	mat[u][u]++,mat[v][v]++,mat[u][v]--,mat[v][u]--; }
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
void build(int sta,int n)
{
	memset(mat,0,sizeof(mat));
	for(int i=1;i<=n;i++,sta>>=1) if(sta&1) 
		for(int j=1;j<=m[i];j++)
			link(eu[i][j],ev[i][j]);
}
int cnt(int x)
{
	int ans=0;
	while(x) ans+=x&1,x>>=1;
	return ans;
}
int main()
{
	int n;
	scanf("%d",&n),n--;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&m[i]);
		for(int j=1;j<=m[i];j++)
			scanf("%d%d",&eu[i][j],&ev[i][j]);
	}
	ll ans=0;
	for(int i=1;i<(1<<n);i++)
	{
		build(i,n);
		ll cur=matrixtree(n);
		ans=(ans+((n-cnt(i))&1?-1:1)*cur+mod)%mod;
	}
	printf("%lld\n",ans);
}