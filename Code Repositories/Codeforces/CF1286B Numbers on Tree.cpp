#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3+5;
int n,p,c[maxn],ans[maxn],siz[maxn],vis[maxn];
vector<int>e[maxn];
void dfs(int u)
{
	siz[u]=1;
	int cnt=0,ok=0;
	for(int i=1;i<=n&&!ok;i++)
	{
		if(!vis[i]) cnt++;
		if(cnt==c[u]+1) 
			ans[u]=i,vis[i]=ok=1;
	}
	for(int v:e[u]) dfs(v),siz[u]+=siz[v];
	if(c[u]>=siz[u]) { puts("NO"); exit(0); }
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p>>c[i],e[p].push_back(i);
	dfs(e[0][0]),puts("YES");
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
}