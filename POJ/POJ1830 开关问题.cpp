#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int mat[55][55];
ll xor_gauss(int n)
{
	for(int i=1;i<=n;i++)
	{
		bool ok=0;
		for(int j=i;j<=n;j++) if(mat[j][i])
		{	swap(mat[i],mat[j]),ok=1; break; }
		if(!ok) continue;
		for(int j=i+1;j<=n;j++)
			if(mat[j][i]) for(int k=n+1;k>=i;k--)
				mat[j][k]^=mat[i][k];
	}
	ll ans=1;
	for(int i=n;i;i--)
	{
		if(!mat[i][i]&&mat[i][n+1])
			return 0;
		else if(!mat[i][i]) ans*=2LL;
		else for(int j=i+1;j<=n;j++)
			if(mat[j][i]) mat[j][n+1]^=mat[i][n+1];
	}
	return ans;
}
int main()
{
	int t,n,x,u,v;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(mat,0,sizeof(mat));
		for(int i=1;i<=n;i++)
			scanf("%d",&mat[i][n+1]),mat[i][i]=1;
		for(int i=1;i<=n;i++)
			scanf("%d",&x),mat[i][n+1]^=x;
		while(scanf("%d%d",&u,&v)&&u)
			mat[u][v]=1;
		ll ans=xor_gauss(n);
		if(!ans) puts("Oh,it's impossible~!!");
		else printf("%lld\n",ans);
	}
}