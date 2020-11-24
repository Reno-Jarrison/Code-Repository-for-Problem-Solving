#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5,inf=0x3f3f3f3f;
char s[maxn][maxn];
int dis[maxn][maxn],vis[maxn][maxn];
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1},n,m;
struct node
{
	int x,y;
	node(int x,int y):x(x),y(y){}
};
deque<node>que;
void push(int x,int y,int d,int id)
{
	if(x>=1&&y>=1&&x<=n&&y<=m&&s[x][y]!='#')
	{
		if(d>=dis[x][y]) return;
		dis[x][y]=d;
		if(id) que.push_back(node(x,y));
		else que.push_front(node(x,y));
	}
}
void bfs(int sx,int sy)
{
	dis[sx][sy]=0;
	que.push_back(node(sx,sy));
	while(!que.empty())
	{
		node cur=que.front(); que.pop_front();
		int x=cur.x,y=cur.y;
		for(int i=0;i<4;i++)
			push(x+dx[i],y+dy[i],dis[x][y],0);
		for(int i=-2;i<=2;i++)
			for(int j=-2;j<=2;j++)
				push(x+i,y+j,dis[x][y]+1,1);
	}
}
int main()
{
	int sx,sy,tx,ty;
	scanf("%d%d%d%d%d%d",&n,&m,&sx,&sy,&tx,&ty);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	memset(dis,inf,sizeof(dis));
	bfs(sx,sy);
	if(dis[tx][ty]==inf) dis[tx][ty]=-1;
	printf("%d\n",dis[tx][ty]);
}