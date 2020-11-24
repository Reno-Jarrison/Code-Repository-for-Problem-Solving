#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5,maxm=2e5+5;
struct edge
{
	int to,id;
	edge(int to,int id):to(to),id(id){}
};
vector<edge>e[maxn];
int eu[maxm],ev[maxm],d[maxn],tag[maxn],idx[maxn],cnt[maxm];
bool cmp(int u,int v)
{	return d[u]<d[v]||(d[u]==d[v]&&u<v); }
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{
		for(int i=1;i<=n;i++)
			e[i].clear(),d[i]=tag[i]=0;
		for(int i=1;i<=m;i++)
			scanf("%d%d",&eu[i],&ev[i]),d[eu[i]]++,d[ev[i]]++,cnt[i]=0;
		for(int i=1;i<=m;i++)
		{
			if(!cmp(eu[i],ev[i])) swap(eu[i],ev[i]);
			e[eu[i]].push_back(edge(ev[i],i));
		}
		for(int i=1;i<=m;i++)
		{
			int u=eu[i],v=ev[i];
			for(auto x:e[u])
				tag[x.to]=i,idx[x.to]=x.id;
			for(auto x:e[v]) if(tag[x.to]==i)
				cnt[i]++,cnt[x.id]++,cnt[idx[x.to]]++;
		}
		ll ans=0;
		for(int i=1;i<=m;i++)
			ans+=1LL*cnt[i]*(cnt[i]-1)/2;
		printf("%lld\n",ans);
	}
}