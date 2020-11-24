#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5,inf=0x3f3f3f3f;
char s[maxn][maxn];
int dis[maxn][maxn];
int dx[8]={-1,-1,0,1,1,1,0,-1},dy[8]={0,1,1,1,0,-1,-1,-1};
int main()
{
	int n,m,q,sx,sy,tx,ty;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d%d%d",&sx,&sy,&tx,&ty);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				dis[i][j]=inf;
		deque<pair<int,int>>que;
		dis[sx][sy]=0;
		que.push_front(make_pair(sx,sy));
		while(!que.empty())
		{
			auto cur=que.front(); que.pop_front();
			int ux=cur.first,uy=cur.second;
			int dir=s[ux][uy]-'0';
			for(int i=0;i<8;i++)
			{
				int vx=ux+dx[i],vy=uy+dy[i];
				if(vx<1||vy<1||vx>n||vy>m) continue;
				int d=dis[ux][uy]+(i!=dir);
				if(d>=dis[vx][vy]) continue;
				dis[vx][vy]=d;
				if(i==dir) que.push_front(make_pair(vx,vy));
				else que.push_back(make_pair(vx,vy));
			}
		}
		printf("%d\n",dis[tx][ty]);
	}
}