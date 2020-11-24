#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=1e4+5;
int tag[maxn],vis[maxn],pow10[4]={1};
struct node
{
	int x,d;
	node(int x,int d):x(x),d(d){}
};
void init(int n)
{
	for(int i=2;i<n;i++)
	{
		if(tag[i]) continue;
		for(int j=2;j*i<n;j++)
			tag[i*j]=1;
	}
	for(int i=1;i<4;i++)
		pow10[i]=pow10[i-1]*10;
}
int update(int x,int pos,int bit)
{
	int tmp=x/pow10[pos]%10*pow10[pos];
	return x-tmp+bit*pow10[pos];
}
int bfs(int s,int t)
{
	queue<node>que;
	vis[s]=1,que.push(node(s,0));
	while(!que.empty())
	{
		node cur=que.front(); que.pop();
		int u=cur.x,d=cur.d;
		if(u==t) return d;
		for(int i=0;i<4;i++)
			for(int j=0;j<=9;j++)
			{
				int v=update(u,i,j);
				if(v<1000||tag[v]||vis[v]) continue;
				vis[v]=1,que.push(node(v,d+1));
			}
	}
	return -1;
}
int main()
{
	init(1e4);
	int t,src,dst;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&src,&dst);
		memset(vis,0,sizeof(vis));
		int ans=bfs(src,dst);
		if(ans==-1) puts("Impossible");
		printf("%d\n",ans);
	}
}