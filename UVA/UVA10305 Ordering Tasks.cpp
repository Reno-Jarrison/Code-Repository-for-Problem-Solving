#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int vis[105],len;
priority_queue<int>q;
vector<int>ans,e[105];
void bfs(int n)
{
	for(int i=1;i<=n;i++)
		if(!vis[i]) q.push(i);
	while(!q.empty())
	{
		int index=q.top(),next;
		q.pop();
		ans.push_back(index);
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
}
int main()
{
	int n,m,i,j;
	while(scanf("%d%d",&n,&m)&&(n||m))
	{
		while(m--)
			scanf("%d%d",&i,&j),e[i].push_back(j),vis[j]++;
		bfs(n);
		len=ans.size();
		for(int i=0;i<len;i++)
			printf("%d ",ans[i]);
		printf("\n");
		ans.clear();
	}
}