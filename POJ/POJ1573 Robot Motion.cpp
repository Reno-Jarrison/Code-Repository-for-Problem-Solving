#include<cstdio>
using namespace std;
int g[15][15],vis[15][15],dis[15][15],n,m,ans,cir;
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int idx(char x)
{
	if(x=='S') return 0;
	if(x=='N') return 1;
	if(x=='E') return 2;
	return 3;
}
void dfs(int x,int y,int d)
{
	if(!x||!y||x>n||y>m) 
	{	ans=d; return; }
	if(vis[x][y])
	{	ans=dis[x][y],cir=d-dis[x][y]; return; }
	vis[x][y]=1,dis[x][y]=d;
	int dir=g[x][y];
	dfs(x+dx[dir],y+dy[dir],d+1);
}
int main()
{
	int beg; char s[15];
	while(scanf("%d%d%d",&n,&m,&beg)&&n)
	{
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(int j=1;j<=m;j++)
				g[i][j]=idx(s[j]),vis[i][j]=0;
		}
		cir=-1,dfs(1,beg,0);
		if(cir!=-1) 
			printf("%d step(s) before a loop of %d step(s)\n",ans,cir);
		else printf("%d step(s) to exit\n",ans);
	}
}