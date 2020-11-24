#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int n,m,zx1,zy1,zx2,zy2,step,vis[2][maxn][maxn];
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
char s[maxn];
struct node
{
	int x,y;
	node(int x,int y):x(x),y(y){}
};
queue<node>que[2];
int dis(int x1,int y1,int x2,int y2)
{	return abs(x1-x2)+abs(y1-y2); }
bool check(int x,int y)
{	return dis(x,y,zx1,zy1)>step*2&&dis(x,y,zx2,zy2)>step*2; }
bool bfs(int tag)
{
	int siz=que[tag].size();
	while(siz--)
	{
		node cur=que[tag].front(); que[tag].pop();
		int ux=cur.x,uy=cur.y;
		if(!check(ux,uy)) continue;
		for(int i=0;i<4;i++)
		{
			int vx=ux+dx[i],vy=uy+dy[i];
			if(vx<1||vy<1||vx>n||vy>m||vis[tag][vx][vy]) continue;
			if(!check(vx,vy)) continue;
			if(vis[tag^1][vx][vy]) return true;
			vis[tag][vx][vy]=1;
			que[tag].push(node(vx,vy));
		}
	}
	return false;
}
int solve(int mx,int my,int gx,int gy)
{
	while(!que[0].empty()) que[0].pop();
	while(!que[1].empty()) que[1].pop();
	que[0].push(node(mx,my)),que[1].push(node(gx,gy));
	vis[0][mx][my]=vis[1][gx][gy]=1,step=0;
	while(++step&&(!que[0].empty()||!que[1].empty()))
		if(bfs(0)||bfs(0)||bfs(0)||bfs(1)) return step;
	return -1;
}
int main()
{
	int t,mx,my,gx,gy;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m),zx1=zx2=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(int j=1;j<=m;j++)
			{
				if(s[j]=='M') mx=i,my=j;
				if(s[j]=='G') gx=i,gy=j;
				if(s[j]=='Z'&&!zx1) zx1=i,zy1=j;
				if(s[j]=='Z'&&zx1) zx2=i,zy2=j;
				vis[0][i][j]=vis[1][i][j]=(s[j]=='X');
			}
		}
		printf("%d\n",solve(mx,my,gx,gy));
	}
}