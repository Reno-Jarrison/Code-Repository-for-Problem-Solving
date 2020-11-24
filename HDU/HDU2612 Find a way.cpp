#include<bits/stdc++.h>
using namespace std;
const int maxn=205,inf=0x3f3f3f3f;
char s[maxn][maxn];
int g[maxn][maxn],vis[maxn][maxn],dis[2][maxn][maxn];
int tot,tx[maxn*maxn],ty[maxn*maxn],n,m;
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
struct pos
{
	int x,y;
	pos(int x,int y):x(x),y(y){}
};
void bfs(int sx,int sy,int tag)
{
	memset(vis,0,sizeof(vis));
	queue<pos>que;
	vis[sx][sy]=1;
	dis[tag][sx][sy]=0;
	que.push(pos(sx,sy));
	while(!que.empty())
	{
		auto cur=que.front(); que.pop();
		int ux=cur.x,uy=cur.y,d=dis[tag][ux][uy];
		for(int i=0;i<4;i++)
		{
			int vx=ux+dx[i],vy=uy+dy[i];
			if(g[vx][vy]||vis[vx][vy]||!vx||!vy||vx>n||vy>m) continue;
			vis[vx][vy]=1,dis[tag][vx][vy]=d+1;
			que.push(pos(vx,vy));
		}
	}
}
int main()
{
	int x1,y1,x2,y2;
	while(~scanf("%d%d",&n,&m))
	{
		tot=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s[i]+1);
			for(int j=1;j<=m;j++)
			{
				if(s[i][j]=='Y') x1=i,y1=j;
				if(s[i][j]=='M') x2=i,y2=j;
				if(s[i][j]=='@') tx[++tot]=i,ty[tot]=j;
				g[i][j]=(s[i][j]=='#');
				dis[0][i][j]=dis[1][i][j]=inf;
			}
		}
		bfs(x1,y1,0),bfs(x2,y2,1);
		int ans=inf;
		for(int i=1;i<=tot;i++)
		{
			int x=tx[i],y=ty[i];
			ans=min(ans,dis[0][x][y]+dis[1][x][y]);
		}
		printf("%d\n",ans*11);
	}
}