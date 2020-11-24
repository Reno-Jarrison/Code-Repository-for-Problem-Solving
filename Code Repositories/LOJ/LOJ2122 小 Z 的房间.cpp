#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=100,mod=1e9;
ll mat[maxn][maxn];
int tot,id[10][10];
ll matrixtree(int n)
{
	ll ans=1;
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
			while(mat[j][i])
			{
				ll p=mat[i][i]/mat[j][i];
				for(int k=i;k<n;k++)
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
void link(int u,int v)
{	mat[u][u]++,mat[v][v]++,mat[u][v]--,mat[v][u]--; }
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	char s[10][10];
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='*') continue;
			id[i][j]=++tot;
			if(s[i-1][j]=='.') 
				link(tot,id[i-1][j]);
			if(s[i][j-1]=='.')
				link(tot,id[i][j-1]);
		}
	}
	printf("%lld\n",matrixtree(tot));
}