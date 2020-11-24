#include<bits/stdc++.h>
#define ll long long
const int maxn=3e5+5;
const ll mod=998244353;
using namespace std;
vector<int>e[maxn];
void link(int u,int v)
{	e[u].push_back(v),e[v].push_back(u); }
int dep[maxn],fat[maxn][20],lg2[maxn]={-1};
void dfs(int u,int f)
{
	dep[u]=dep[f]+1,fat[u][0]=f;
	for(int i=1;(1<<i)<=dep[u];i++)
		fat[u][i]=fat[fat[u][i-1]][i-1];
	for(int i=0;i<(int)e[u].size();i++)
		if(e[u][i]!=f) dfs(e[u][i],u);
}
int getlca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y])
		x=fat[x][lg2[dep[x]-dep[y]]];
	if(x==y) return x;
	for(int i=lg2[dep[x]];~i;i--)
		if(fat[x][i]!=fat[y][i])
			x=fat[x][i],y=fat[y][i];
	return fat[x][0];
}
ll power[maxn][55],sum[maxn][55];
void init(int n)
{
	for(int i=1;i<=n;i++) 
		power[i][0]=1,lg2[i]=lg2[i>>1]+1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=50;j++)
		{
			power[i][j]=power[i][j-1]*i%mod;
			sum[i][j]=(sum[i-1][j]+power[i][j])%mod;
		}
}
int main()
{
	int n,m,u,v,k;
	scanf("%d",&n);
	init(n);
	for(int i=1;i<n;i++)
		scanf("%d%d",&u,&v),link(u,v);
	dep[0]=-1,dfs(1,0),dep[0]=0;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&u,&v,&k);
		int lca=getlca(u,v),flca=fat[lca][0];
		ll sum1=(sum[dep[u]][k]+sum[dep[v]][k])%mod;
		ll sum2=(sum[dep[lca]][k]+sum[dep[flca]][k])%mod;
		printf("%lld\n",(sum1-sum2+mod)%mod);
	}
}