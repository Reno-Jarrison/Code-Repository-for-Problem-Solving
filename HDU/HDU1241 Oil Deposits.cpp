#include<bits/stdc++.h>
using namespace std;
int vis[205][205],g[205][205],n,m;
int dx[8]={1,1,1,-1,-1,-1,0,0},dy[8]={1,-1,0,1,-1,0,1,-1};
void dfs(int x,int y)
{
	vis[x][y]=1;
	for(int i=0;i<8;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(!nx||!ny||nx>n||ny>m||!g[nx][ny]||vis[nx][ny]) continue;
		dfs(nx,ny);
	}
}
int main()
{
	while(scanf("%d%d",&n,&m)&&n)
	{
		char s[205];
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(int j=1;j<=m;j++)
				g[i][j]=(s[j]=='@'),vis[i][j]=0;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(!vis[i][j]&&g[i][j]) dfs(i,j),ans++;
		printf("%d\n",ans);
	}
}