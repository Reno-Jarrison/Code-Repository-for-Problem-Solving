#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=3e3+5;
int mat[maxn],g1[55][55],g2[55][55];
bool vis[maxn],g[55][55],e[maxn][maxn];
bool dfs(int u,int m)
{
	for(int v=1;v<=m;v++)
	{
		if(!e[u][v]||vis[v]) continue;	
		vis[v]=true;
		if(!mat[v]||dfs(mat[v],m))
		{	mat[v]=u; return true; }
	}
	return false;
}
int hungary(int r,int c)
{
	memset(mat,0,sizeof(mat));
	int ans=0;
	for(int i=1;i<=r;i++)
		memset(vis,0,sizeof(vis)),ans+=dfs(i,c);
	return ans;
}
int main()
{
	int t,r,c;
	char tmp[55];
	scanf("%d",&t);
	while(t--)
	{
		memset(g,0,sizeof(g));
		memset(g1,0,sizeof(g1));
		memset(g2,0,sizeof(g2));
		memset(e,0,sizeof(e));
		scanf("%d%d",&r,&c);
		for(int i=1;i<=r;i++)
		{
			scanf("%s",tmp+1);
			for(int j=1;j<=c;j++)
				g[i][j]=tmp[j]=='*'?true:false;
		}
		int nx=0,ny=0;
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				g1[i][j]=g[i][j]?(g[i][j-1]?nx:++nx):0;
		for(int i=1;i<=c;i++)
			for(int j=1;j<=r;j++)
				g2[j][i]=g[j][i]?(g[j-1][i]?ny:++ny):0;
		for(int i=1;i<=r;i++)
			for(int j=1;j<=c;j++)
				if(g1[i][j]&&g2[i][j])
					e[g1[i][j]][g2[i][j]]=true;
		printf("%d\n",hungary(nx,ny));
	}
}