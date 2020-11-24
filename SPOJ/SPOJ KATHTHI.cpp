#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5,inf=0x3f3f3f3f;
char s[maxn][maxn];
int dis[maxn][maxn];
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s[i]+1);
			for(int j=1;j<=m;j++)
				dis[i][j]=inf;
		}
		deque<pair<int,int>>que;
		dis[1][1]=0;
		que.push_front(make_pair(1,1));
		while(!que.empty())
		{
			pair<int,int> cur=que.front(); que.pop_front();
			int ux=cur.first,uy=cur.second;
			for(int i=0;i<4;i++)
			{
				int vx=ux+dx[i],vy=uy+dy[i];
				if(vx>=1&&vy>=1&&vx<=n&&vy<=m)
				{
					int flag=s[ux][uy]!=s[vx][vy],d=dis[ux][uy]+flag;
					if(d<dis[vx][vy])
					{
						dis[vx][vy]=d;
						if(flag) que.push_back(make_pair(vx,vy));
						else que.push_front(make_pair(vx,vy));
					}
				}
			}
		}
		printf("%d\n",dis[n][m]);
	}
}