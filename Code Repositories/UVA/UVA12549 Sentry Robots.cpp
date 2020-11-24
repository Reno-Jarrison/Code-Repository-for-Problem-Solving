#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=105,maxm=5e3+5;
int g[maxn][maxn],ng[maxm][maxn],mat[maxm];
bool e[maxm][maxm],vis[maxm];
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
int hungary(int n,int m)
{
	memset(mat,0,sizeof(mat));
	int ans=0;
	for(int i=1;i<=n;i++)
		memset(vis,0,sizeof(vis)),ans+=dfs(i,m);
	return ans;
}
int main()
{
	int t,x,y,n,m,px,py;
	scanf("%d",&t);
	while(t--)
	{
		memset(g,0,sizeof(g));
		memset(ng,0,sizeof(ng));
		memset(e,0,sizeof(e));
		int nx=0,ny=0;
		scanf("%d%d",&x,&y);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d%d",&px,&py),g[px][py]=1;		
		scanf("%d",&m);
		for(int i=1;i<=m;i++)
			scanf("%d%d",&px,&py),g[px][py]=-1;
		for(int i=1;i<=x;i++,nx++)
		{
			int cnt=0;	
			for(int j=1;j<=y;j++)
				if(g[i][j]==1) ng[nx+1][j]=1,cnt++;
				else if(g[i][j]==-1) ng[nx+1][j]=-1,cnt?nx++:0,cnt=0;
		}
		for(int i=1;i<=y;i++,ny++)
		{
			int cnt=0;
			for(int j=1;j<=nx;j++)
				if(ng[j][i]==1) e[j][ny+1]=true,cnt++;
				else if(ng[j][i]==-1) cnt?ny++:0,cnt=0;
		}
		printf("%d\n",hungary(nx,ny));
	}
}