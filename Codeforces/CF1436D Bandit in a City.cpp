#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5;
vector<int>e[maxn];
ll w[maxn],siz[maxn],mxv[maxn],sum[maxn];
void dfs(int u)
{
	if(e[u].empty()) 
	{	siz[u]=1,mxv[u]=w[u]; return; }
	for(int v:e[u])
	{
		dfs(v);
		mxv[u]=max(mxv[u],mxv[v]);
		siz[u]+=siz[v];
		sum[u]+=sum[v];
	}
	for(int v:e[u])
		sum[u]+=(mxv[u]-mxv[v])*siz[v];
	ll dec=min(w[u],sum[u]);
	sum[u]-=dec,w[u]-=dec;
	ll inc=w[u]/siz[u];
	mxv[u]+=inc,w[u]-=inc*siz[u];
	if(w[u]) mxv[u]++,sum[u]+=siz[u]-w[u];
}
int main()
{
	int n,x;
	scanf("%d",&n);
	for(int i=2;i<=n;i++)
		scanf("%d",&x),e[x].push_back(i);
	for(int i=1;i<=n;i++)
		scanf("%lld",&w[i]);
	dfs(1);
	printf("%lld\n",mxv[1]);
}