#include<cstdio>
#include<queue>
using namespace std;
struct pos
{	
	int x,y;
	pos(int x=0,int y=0):x(x),y(y){}
}pre[6][6];
int vis[6][6],dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
void bfs()
{
	queue<pos>que;
	que.push(pos(1,1));
	vis[1][1]=1;
	while(!que.empty())
	{
		pos u=que.front(); que.pop();
		int ux=u.x,uy=u.y;
		if(ux==5&&uy==5) return;
		for(int i=0;i<4;i++)
		{
			int vx=ux+dx[i],vy=uy+dy[i];
			if(vx<1||vy<1||vx>5||vy>5||vis[vx][vy]) continue;
			vis[vx][vy]=1;
			que.push(pos(vx,vy));
			pre[vx][vy]=pos(ux,uy);
		}
	}
}
void dfs(int x,int y)
{
	if(!x&&!y) return;
	pos las=pre[x][y];
	dfs(las.x,las.y);
	printf("(%d, %d)\n",x-1,y-1);
}
int main()
{
	for(int i=1;i<=5;i++)
		for(int j=1;j<=5;j++)
			scanf("%d",&vis[i][j]);
	bfs(),dfs(5,5);
}