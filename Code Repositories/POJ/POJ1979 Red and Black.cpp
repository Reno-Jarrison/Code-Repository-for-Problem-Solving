#include<cstdio>
using namespace std;
int vis[25][25],n,m,ans;
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
void dfs(int x,int y)
{
	vis[x][y]=1,ans++;
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(!nx||!ny||nx>n||ny>m||vis[nx][ny]) continue;
		dfs(nx,ny); 
	}
}
int main()
{
	char s[25];
	while(scanf("%d%d",&m,&n)&&n)
	{
		int sx,sy;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(int j=1;j<=m;j++)
			{
				if(s[j]=='@') sx=i,sy=j;
				vis[i][j]=(s[j]=='#');
			}
		}
		ans=0,dfs(sx,sy);
		printf("%d\n",ans);
	}
}