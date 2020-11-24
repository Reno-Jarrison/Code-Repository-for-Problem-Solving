#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
int w[maxn],p[maxn],f[maxn],pre[maxn],vis[maxn];
bool cmp(int x,int y)
{	return w[x]>w[y]; }
vector<int>e[maxn];
void link(int u,int v)
{	e[u].push_back(v),e[v].push_back(u); }
int find(int x)
{ 	return x==f[x]?x:f[x]=find(f[x]); }
int main()
{
	int t,n,m,u,v;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&w[i]);
			p[i]=f[i]=i;
			pre[i]=vis[i]=0;
			e[i].clear();
		}
		for(int i=1;i<=m;i++)
			scanf("%d%d",&u,&v),link(u,v);
		sort(p+1,p+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			int u=p[i];
			vis[u]=1;
			for(int v:e[u]) if(vis[v])
			{
				v=find(v);
				if(v==u) continue;
				pre[v]=f[v]=u;
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++)
			ans+=w[i]-w[pre[i]];
		printf("%lld\n",ans);
	}
}