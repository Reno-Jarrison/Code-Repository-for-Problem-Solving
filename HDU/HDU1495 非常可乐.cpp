#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int vis[maxn][maxn][maxn],s,n,m;
struct node
{
	int a,b,c,d;
	node(int a,int b,int c,int d):
		a(a),b(b),c(c),d(d){}
};
void update(int a,int b,int c,int d,queue<node>& que)
{
	if(vis[a][b][c]) return;
	vis[a][b][c]=1;
	que.push(node(a,b,c,d));
}
int bfs()
{
	queue<node>que;
	que.push(node(s,0,0,0));
	vis[s][0][0]=1;
	while(!que.empty())
	{
		node u=que.front(); que.pop();
		int a=u.a,b=u.b,c=u.c,d=u.d;
		if((a==b&&!c)||(a==c&&!b)||(b==c&&!a)) return d;
		update(a-min(a,n-b),b+min(a,n-b),c,d+1,que);
		update(a-min(a,m-c),b,c+min(a,m-c),d+1,que);
		update(a+min(b,s-a),b-min(b,s-a),c,d+1,que);
		update(a,b-min(b,m-c),c+min(b,m-c),d+1,que);
		update(a+min(c,s-a),b,c-min(c,s-a),d+1,que);
		update(a,b+min(c,n-b),c-min(c,n-b),d+1,que);
	}
	return -1;
}
int main()
{
	while(scanf("%d%d%d",&s,&n,&m)&&s)
	{
		for(int i=0;i<=s;i++)
			for(int j=0;j<=n;j++)
				for(int k=0;k<=m;k++)
					vis[i][j][k]=0;
		int ans=bfs();
		if(ans==-1) puts("NO");
		else printf("%d\n",ans);
	}
}