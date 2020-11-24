#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+5;
vector<int>e[maxn];
ll sum1,sum2;
int siz[maxn],n;
void dfs1(int u)
{
	siz[u]=1;
	for(int v:e[u])
		dfs1(v),siz[u]+=siz[v];
}
void dfs2(int u,ll tmp)
{
	sum1+=siz[u];
	sum2=max(sum2,tmp);
	for(int v:e[u])
		dfs2(v,tmp+n-siz[v]);
}
int main()
{
	int t,p;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=2;i<=n;i++)
			scanf("%d",&p),e[p].push_back(i);
		sum1=sum2=0;
		dfs1(1),dfs2(1,0);
		printf("%lld\n",sum1+sum2);
	}
}