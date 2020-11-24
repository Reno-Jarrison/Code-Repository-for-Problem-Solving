#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
vector<int>e[maxn];
set<int>s[2];
int a[2],flag[2][maxn];
void link(int u,int v)
{	e[u].push_back(v),e[v].push_back(u); }
void dfs(int u,int tag)
{
	flag[tag][u]=true;
	if(u==a[tag^1]) return;
	s[tag].insert(u);
	for(int v:e[u])
		if(!flag[tag][v]) dfs(v,tag);
}
int main()
{
	int T,n,m,u,v;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d%d",&n,&m,&a[0],&a[1]);
		for(int i=1;i<=n;i++) e[i].clear();
		s[0].clear(),s[1].clear();
		for(int i=1;i<=m;i++)
			scanf("%d%d",&u,&v),link(u,v);
		dfs(a[0],0),dfs(a[1],1);
		int cnt[2]={0};
		for(int i=1;i<=n;i++) 
			if(i!=a[0]&&i!=a[1]&&(s[0].count(i)^s[1].count(i)))
				cnt[0]+=s[0].count(i),cnt[1]+=s[1].count(i);
		printf("%lld\n",1LL*cnt[0]*cnt[1]);
	}
}