#include<bits/stdc++.h>
using namespace std;
char s[55][55],o[105];
int dir[4],vis[4],len,ans,n,m,sx,sy,ex,ey;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
void dfs(int step)
{
	if(step==4)
	{
		int px=sx,py=sy;
		for(int i=0;i<len;i++)
		{
			int d=dir[o[i]-'0'];
			px+=dx[d],py+=dy[d];
			if(px<1||py<1||px>n||py>m||s[px][py]=='#') break;
			if(px==ex&&py==ey)
				{	ans++; break; }
		}
		return;
	}
	for(int i=0;i<4;i++)
		if(!vis[i])
		{
			dir[step]=i,vis[i]=1;
			dfs(step+1),vis[i]=0;
		}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s[i]+1);
		for(int j=1;j<=m;j++)
		{
			if(s[i][j]=='S')
				sx=i,sy=j;
			if(s[i][j]=='E')
				ex=i,ey=j;
			
		}
	}
	scanf("%s",o);
	len=strlen(o);
	dfs(0);
	printf("%d\n",ans);
}