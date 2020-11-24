#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define maxn 100005
using namespace std;
vector<int>e[maxn];
queue<int>q;
int f[maxn],vis[maxn];
int find(int x)
{
	if(f[x]!=x) f[x]=find(f[x]);
	return f[x];
}
void join(int x,int y)
	{ f[find(x)]=find(y); }
bool bfs(int beg)
{
	q.push(beg);
	vis[beg]=1;
	while(!q.empty())
	{
		int index=q.front();
		q.pop();
		for(int i=0;i<e[index].size();i++)
		{
			int next=e[index][i];
			if(!vis[next])
				vis[next]=-vis[index],q.push(next);
			else if(vis[index]==vis[next]) 
				return false;
		}
	}
	return true;
}
int main()
{
	int t,n,m,s,a,b;
	scanf("%d",&t);
	for(int k=1;k<=t;k++)
	{
		scanf("%d%d%d",&n,&m,&s);
		memset(vis,0,sizeof(vis));
		for(int i=0;i<n;i++) f[i]=i,e[i].clear();
		for(int i=0;i<m;i++)
		{
			scanf("%d%d",&a,&b);
			e[a].push_back(b);
			e[b].push_back(a);
			join(a,b);
		}
		int cnt=0,flag=0;
		for(int i=0;i<n;i++)
			if(f[i]==i) cnt++;
		flag=(cnt==1)?bfs(s):1;
		printf("Case %d: %s\n",k,flag?"NO":"YES");
	} 
}