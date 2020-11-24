#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std; 
const int maxn=505,inf=0x3f3f3f3f;
int w[maxn][maxn],lx[maxn],ly[maxn],mat[maxn],slack[maxn];
bool visx[maxn],visy[maxn];
bool dfs(int u,int ny)
{
	visx[u]=true;
	for(int v=1;v<=ny;v++)
	{
		if(visy[v]) continue;
		int tmp=lx[u]+ly[v]-w[u][v];
		if(tmp) slack[v]=min(slack[v],tmp);
		else
		{
			visy[v]=true;
			if(!mat[v]||dfs(mat[v],ny))
			{	mat[v]=u; return true; }	
		}
	}
	return false;
}
int km(int nx,int ny)
{
	memset(mat,0,sizeof(mat));
	memset(lx,0,sizeof(lx));
	memset(ly,0,sizeof(ly));
	for(int i=1;i<=nx;i++)
		for(int j=1;j<=ny;j++)
			lx[i]=max(lx[i],w[i][j]);
	for(int i=1;i<=nx;i++)
	{
		memset(slack,inf,sizeof(slack));
		while(true)
		{
			memset(visx,0,sizeof(visx));
			memset(visy,0,sizeof(visy));
			if(dfs(i,ny)) break;
			int delta=inf;
			for(int i=1;i<=ny;i++)
				if(!visy[i]&&delta>slack[i])
					delta=slack[i];
			for(int i=1;i<=nx;i++)
				if(visx[i]) lx[i]-=delta;
			for(int i=1;i<=ny;i++)
				visy[i]?ly[i]+=delta:slack[i]-=delta;
		}
	}
	int ans=0;
	for(int i=1;i<=nx;i++)
		ans+=w[mat[i]][i];
	return ans;
}
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&w[i][j]);
		int ans=km(n,n);
		for(int i=1;i<=n;i++)
			printf("%d%c",lx[i],i==n?'\n':' ');
		puts("");
		for(int i=1;i<=n;i++)
			printf("%d%c",ly[i],i==n?'\n':' ');
		puts(""),printf("%d\n",ans);
	}
}