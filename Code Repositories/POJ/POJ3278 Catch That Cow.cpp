#include<cstdio>
#include<queue>
using namespace std;
const int maxn=2e5+5;
int dis[maxn];
int bfs(int s,int t)
{
	queue<int>que;
	que.push(s);
	while(!que.empty())
	{
		int u=que.front(); que.pop();
		if(u==t) return dis[u];
		if(u<t&&!dis[u+1])
			dis[u+1]=dis[u]+1,que.push(u+1);
		if(u>0&&!dis[u-1])
			dis[u-1]=dis[u]+1,que.push(u-1);
		if(u<t&&!dis[u*2])
			dis[u*2]=dis[u]+1,que.push(u*2);
	}
	return -1;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	printf("%d",bfs(n,k));
}