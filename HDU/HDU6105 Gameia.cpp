#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
vector<int>e[maxn];
int cnt[2];
void link(int u,int v)
{	e[u].push_back(v); }
void dfs(int u,int f,int col)
{
	cnt[col]++;
	for(int v:e[u]) if(v!=f)
		dfs(v,u,!col);
}
int main()
{
	int t,n,k,x;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++)
			e[i].clear();
		for(int i=2;i<=n;i++)
			scanf("%d",&x),link(x,i);
		cnt[0]=cnt[1]=0;
		dfs(1,0,0);
		puts(cnt[0]!=cnt[1]||k<n/2-1?"Alice":"Bob");
	}
}