#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
#define ll long long
#define min(a,b) ((a<b)?a:b) 
using namespace std;
int vis[100005],len;
priority_queue<int,vector<int>,less<int> >q;
vector<int>e[100005];
ll bfs(int n)
{
	ll ans=0,minm=0x3f3f3f3f;
	for(int i=1;i<=n;i++)
		if(!vis[i]) q.push(i);
	while(!q.empty())
	{
		int index=q.top(),next;
		q.pop();
		minm=min(minm,index);
		ans+=minm;
		len=e[index].size();
		for(int i=0;i<len;i++)
		{
			next=e[index][i];
			vis[next]--;
			if(!vis[next]) 
				q.push(next);
		}
		e[index].clear();
	}
	return ans;
}
int main()
{
	int t,n,m,i,j;
	scanf("%d",&t);
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		scanf("%d%d",&n,&m);
		while(m--)
			scanf("%d%d",&i,&j),e[i].push_back(j),vis[j]++;
		printf("%lld\n",bfs(n));
	}
}