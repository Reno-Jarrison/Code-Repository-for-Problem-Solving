#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
int vis[35][35][35],sx,sy,sz,tx,ty,tz;
int dx[6]={1,-1,0,0,0,0},dy[6]={0,0,1,-1,0,0},dz[6]={0,0,0,0,1,-1};
struct node
{
	int x,y,z,d;
	node(int x,int y,int z,int d):x(x),y(y),z(z),d(d){}
};
int bfs(int x,int y,int z)
{
	queue<node>que;
	que.push(node(sx,sy,sz,0));
	while(!que.empty())
	{
		node u=que.front(); que.pop();
		int ux=u.x,uy=u.y,uz=u.z,d=u.d;
		if(ux==tx&&uy==ty&&uz==tz) return d;
		vis[ux][uy][uz]=1;
		for(int i=0;i<6;i++)
		{
			int vx=ux+dx[i],vy=uy+dy[i],vz=uz+dz[i];
			if(!vx||!vy||!vz||vx>x||vy>y||vz>z||vis[vx][vy][vz]) continue;
			vis[vx][vy][vz]=1;
			que.push(node(vx,vy,vz,d+1));
		}
	}
	return -1;
}
int main()
{
	int x,y,z;
	while(scanf("%d%d%d",&z,&x,&y)&&z)
	{
		char s[35];
		for(int i=1;i<=z;i++)
			for(int j=1;j<=x;j++)
			{
				scanf("%s",s+1);
				for(int k=1;k<=y;k++)
				{
					if(s[k]=='S') sx=j,sy=k,sz=i;
					if(s[k]=='E') tx=j,ty=k,tz=i;
						vis[j][k][i]=(s[k]=='#');
				}
			}
		int ans=bfs(x,y,z);
		if(ans==-1) puts("Trapped!");
		else printf("Escaped in %d minute(s).\n",ans);
	}
}