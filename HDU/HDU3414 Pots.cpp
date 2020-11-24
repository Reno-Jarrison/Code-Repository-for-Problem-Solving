#include<cstdio>
#include<queue>
using namespace std;
const int maxn=105;
int vis[maxn][maxn],ux,uy,ud,resa,resb;
char s[3][5]={"FILL","DROP","POUR"};
struct pos
{
	int x,y,d;
	pos(int x=0,int y=0,int d=0):x(x),y(y),d(d){}
}pre[maxn][maxn];
struct node
{
	int o,p1,p2;
	node(int o=0,int p1=0,int p2=0):o(o),p1(p1),p2(p2){}	
}opt[maxn][maxn];
queue<pos>que;
void update(int vx,int vy,int o,int p1,int p2)
{
	if(vis[vx][vy]) return;
	vis[vx][vy]=1;
	que.push(pos(vx,vy,ud+1));
	pre[vx][vy]=pos(ux,uy);
	opt[vx][vy]=node(o,p1,p2);
}
int bfs(int a,int b,int c)
{
	que.push(pos(0,0,0));
	vis[0][0]=1;
	while(!que.empty())
	{
		pos cur=que.front(); que.pop();
		ux=cur.x,uy=cur.y,ud=cur.d;
		if(ux==c||uy==c) 
		{	resa=ux,resb=uy; return ud; };
		update(a,uy,0,1,0);
		update(ux,b,0,2,0);
		update(0,uy,1,1,0);
		update(ux,0,1,2,0);
		update(ux-min(ux,b-uy),uy+min(ux,b-uy),2,1,2);
		update(ux+min(uy,a-ux),uy-min(uy,a-ux),2,2,1);
	}
	return -1;
}
void dfs(int x,int y)
{
	if(!x&&!y) return;
	pos las=pre[x][y];
	dfs(las.x,las.y);
	node sol=opt[x][y];
	printf("%s",s[sol.o]);
	if(sol.o==2) printf("(%d,%d)\n",sol.p1,sol.p2);
	else printf("(%d)\n",sol.p1);
}
int main()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	int ans=bfs(a,b,c);
	if(ans==-1) puts("impossible");
	else printf("%d\n",ans),dfs(resa,resb);
}