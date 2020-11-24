#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e3+5;
int mat[maxn];
bool e[maxn][maxn],vis[maxn];
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
	int n,m,k,id,u,v;
	while(scanf("%d",&n)&&n)
	{
		memset(e,0,sizeof(e));
		scanf("%d%d",&m,&k);
		for(int i=1;i<=k;i++)
			scanf("%d%d%d",&id,&u,&v),e[u][v]=true;
		printf("%d\n",hungary(n,m));
	}
}
