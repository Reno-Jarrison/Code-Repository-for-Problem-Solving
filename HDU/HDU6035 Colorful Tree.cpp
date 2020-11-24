#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
vector<int>e[maxn];
ll ans;
int col[maxn],siz[maxn],cnt[maxn];
void link(int u,int v)
{	e[u].push_back(v),e[v].push_back(u); }
ll C2(int x) { return 1LL*x*(x-1)/2; }
void dfs(int u,int f)
{
	siz[u]=1;
	int las=cnt[col[u]];
	for(int v:e[u]) if(v!=f)
	{
		int tmp=cnt[col[u]];
		dfs(v,u);
		siz[u]+=siz[v];
		ans-=C2(siz[v]-(cnt[col[u]]-tmp));
	}
	cnt[col[u]]=las+siz[u];
}
int main()
{
	int n,u,v,ks=0;
	while(~scanf("%d",&n))
	{
		fill(cnt+1,cnt+n+1,0);
		set<int>st;
		for(int i=1;i<=n;i++)
			scanf("%d",&col[i]),e[i].clear(),st.insert(col[i]);
		for(int i=1;i<n;i++)
			scanf("%d%d",&u,&v),link(u,v);
		ans=C2(n)*st.size(),dfs(1,0);
		for(int x:st) ans-=C2(n-cnt[x]);
		printf("Case #%d: %lld\n",++ks,ans);
	}
}