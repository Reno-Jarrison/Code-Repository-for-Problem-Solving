#include<cstdio>
#include<cstring>
#include<queue>
#include<iostream>
#define maxn 2005
using namespace std;
bool vis[maxn][maxn],r[maxn][maxn],c[maxn][maxn];
int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0}; 
struct node 
{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){}
};
int main()
{
	int t,n,m,q,x,y;
	scanf("%d",&t);
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		memset(r,0,sizeof(r));
		memset(c,0,sizeof(c)); 
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=q;i++)
		{
			scanf("%d%d",&x,&y);
			if(vis[x][y]) { printf("0\n"); continue; }  
			int cnt=0,tx,ty;
			queue<node>q;
			r[x][y]=c[x][y]=true;
			q.push(node(x,y));
			while(!q.empty())
			{
				tx=q.front().x;
				ty=q.front().y;
				q.pop();
				if(!tx||tx==n+1||!ty||ty==m+1) continue;
				if(vis[tx][ty]||!r[tx][ty]||!c[tx][ty]) continue;
				vis[tx][ty]=true,cnt++;
				r[tx][ty-1]=r[tx][ty+1]=true;
				c[tx-1][ty]=c[tx+1][ty]=true;
				for(int i=0;i<4;i++)
					q.push(node(tx+dx[i],ty+dy[i]));
			}
			printf("%d\n",cnt);
		}
	}
	
}