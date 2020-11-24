#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5,inf=0x3f3f3f3f;
int dis[maxn];
set<int>st1,st2;
vector<int>e[maxn];
void init(int n)
{
	st1.clear(),st2.clear();
	for(int i=1;i<=n;i++) e[i].clear();
	memset(dis,inf,sizeof(dis));
}
void bfs(int s)
{
	queue<int>q;
	set<int>::iterator it;
	q.push(s),dis[s]=0;
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=0;i<(int)e[u].size();i++)
		{
			int v=e[u][i];
			if(!st1.count(v)) continue;
			st1.erase(v),st2.insert(v);
		}
		for(it=st1.begin();it!=st1.end();it++)
			q.push(*it),dis[*it]=dis[u]+1;
		st1=st2,st2.clear();
	}
}
int main()
{
	int t,n,m,u,v,s;
	scanf("%d",&t);
	while(t--)
	{
		bool fst=true;
		scanf("%d%d",&n,&m);
		init(n);
		for(int i=1;i<=m;i++)
		{
			scanf("%d%d",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		scanf("%d",&s);
		for(int i=1;i<=n;i++)
			if(i!=s) st1.insert(i);
		bfs(s);
		for(int i=1;i<=n;i++) if(i!=s)
		{
			fst?fst=false:putchar(' ');
			printf("%d",dis[i]<inf?dis[i]:-1);
		}
		puts("");
	}
}
