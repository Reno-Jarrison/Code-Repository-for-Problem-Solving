#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define maxn 1000005
#define mod 100003
using namespace std;
int dist[maxn],vis[maxn],ans[maxn];
vector<int>e[maxn];
struct cmp
{
	bool operator ()(int x,int y)
		{ return dist[x]>dist[y]; }
};
priority_queue<int,vector<int>,cmp>q;
void dijstra(int sta)
{
	memset(dist,0x3f,sizeof(dist));
	q.push(sta);
	dist[sta]=0,ans[sta]=1;
	while(!q.empty())
	{
		int rt=q.top(),len=e[rt].size(),next;
		q.pop();
		if(vis[rt]) continue;
		vis[rt]=1;
		for(register int i=0;i<len;i++)
		{
			next=e[rt][i];
			if(dist[next]>dist[rt]+1) 
				dist[next]=dist[rt]+1,ans[next]=ans[rt],q.push(next);
			else if(dist[next]==dist[rt]+1) 
				ans[next]+=ans[rt],ans[next]%=mod;
		}
	}  
}
int main()
{
	int n,m,x,y;
	scanf("%d%d",&n,&m);
	for(register int i=0;i<m;i++)
		scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
	dijstra(1);
	for(register int i=1;i<=n;i++)
		printf("%d\n",ans[i]);
} 