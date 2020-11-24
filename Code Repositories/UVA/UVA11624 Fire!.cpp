#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
char s[maxn];
int g[maxn][maxn],vis[maxn][maxn],dis[maxn][maxn],n,m;
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
struct node
{
	int x,y,d;
	node(int x,int y,int d):x(x),y(y),d(d){}
};
vector<node>vec;
int bfs(int x,int y,int tag)
{
	queue<node>que;
	if(tag) vis[x][y]=1,que.push(node(x,y,0));
	else for(node p:vec) 
		que.push(p),vis[p.x][p.y]=1;
	while(!que.empty())
	{
		node cur=que.front(); que.pop();
		int ux=cur.x,uy=cur.y,d=cur.d;
		if(!tag) dis[ux][uy]=d;
		if(tag&&(ux==1||uy==1||ux==n||uy==m)) return d+1;
		for(int i=0;i<4;i++)
		{
			int vx=ux+dx[i],vy=uy+dy[i];
			if(!vx||!vy||vx>n||vy>m||g[vx][vy]||vis[vx][vy]) continue;
			vis[vx][vy]=1;
			if(tag&&d+1>=dis[vx][vy]) continue;
			que.push(node(vx,vy,d+1));
		}
	}
	return -1;
}
int main()
{
	int t,sx,sy;
	scanf("%d",&t);
	while(t--)
	{
		vec.clear();
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(int j=1;j<=m;j++)
			{
				if(s[j]=='F') vec.push_back(node(i,j,0));
				if(s[j]=='J') sx=i,sy=j;
				g[i][j]=(s[j]=='#'),vis[i][j]=0;
				dis[i][j]=0x3f3f3f3f;
			}
		}
		bfs(0,0,0);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++) 
				vis[i][j]=0;
		int ans=bfs(sx,sy,1);
		if(ans==-1) puts("IMPOSSIBLE");
		else printf("%d\n",ans);
	}
}