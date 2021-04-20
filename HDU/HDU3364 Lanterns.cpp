#include<bits/stdc++.h>
#define ll long long
using namespace std;
int buf[55][55],mat[55][55];
ll xor_gauss(int n,int m)
{
	int r,c;
	for(r=1,c=1;r<=n&&c<=m;r++,c++)
	{
		for(int i=r;i<=n;i++) if(mat[i][c]) 
		{	swap(mat[r],mat[i]); break; }
		if(!mat[r][c]) 
		{	r--; continue; }
		for(int i=r+1;i<=n;i++)
			if(mat[i][c]) for(int j=n+1;j>=c;j--)
				mat[i][j]^=mat[r][j];
	}
	for(int i=r;i<=n;i++)
		if(mat[i][m+1]) return 0;
	return 1LL<<(m-r+1);
}
int main()
{
	int t,n,m,k,x,q,ks=0;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		memset(buf,0,sizeof(buf));
		for(int i=1;i<=m;i++)
		{
			scanf("%d",&k);
			for(int j=1;j<=k;j++)
				scanf("%d",&x),buf[x][i]=1;
		}
		scanf("%d",&q);
		printf("Case %d:\n",++ks);
		while(q--)
		{
			memcpy(mat,buf,sizeof(buf));
			for(int i=1;i<=n;i++)
				scanf("%d",&mat[i][m+1]);
			ll ans=xor_gauss(n,m);
			printf("%lld\n",ans);
		}
	}
}