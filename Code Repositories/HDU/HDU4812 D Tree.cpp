#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5,mod=1e6+3;
int siz[maxn],son[maxn],vis[maxn],w[maxn],inv[mod];
int idx[mod],tmp[maxn],dis[maxn],k,a,b,ntot;
vector<int>e[maxn];
void link(int u,int v)
{	e[u].push_back(v),e[v].push_back(u); }
void update(int l,int r)
{
	if(l>r) swap(l,r);
	if(l<a) a=l,b=r;
	else if(l==a) b=min(b,r);
}
void getroot(int u,int f,int tot,int& rt)
{
	siz[u]=1,son[u]=0;
	for(int v:e[u]) if(v!=f&&!vis[v])
	{
		getroot(v,u,tot,rt);
		siz[u]+=siz[v];
		son[u]=max(son[u],siz[v]);
	}
	son[u]=max(son[u],tot-siz[u]);
	if(son[u]<son[rt]) rt=u;
}
void dfs(int u,int f,int pro)
{
	dis[u]=pro,tmp[++ntot]=u;
	for(int v:e[u]) if(v!=f&&!vis[v])
		dfs(v,u,1LL*pro*w[v]%mod);
}
void solve(int u)
{
	idx[w[u]]=u;
	int val=1LL*k*w[u]%mod;
	for(int v:e[u]) if(!vis[v])
	{
		ntot=0,dfs(v,u,1LL*w[u]*w[v]%mod);
		for(int i=1;i<=ntot;i++)
		{
			int id=1LL*val*inv[dis[tmp[i]]]%mod;
			if(idx[id]) update(idx[id],tmp[i]);
		}
		for(int i=1;i<=ntot;i++)
			if(!idx[dis[tmp[i]]]||idx[dis[tmp[i]]]>tmp[i])
				idx[dis[tmp[i]]]=tmp[i];
	}
	for(int v:e[u]) if(!vis[v])
	{
		ntot=0,dfs(v,u,1LL*w[u]*w[v]%mod);
		for(int i=1;i<=ntot;i++)
			idx[dis[tmp[i]]]=0;
	}
	idx[w[u]]=0;
}
void dnc(int u)
{
	solve(u),vis[u]=1;
	for(int v:e[u]) if(!vis[v])
	{
		int rt=0;
		getroot(v,u,siz[v],rt),dnc(rt);
	}
}
void init(int n)
{
	inv[1]=1;
	for(int i=2;i<n;i++)
		inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;
}
int main()
{
	int n,u,v,rt;
	init(mod);
	while(~scanf("%d%d",&n,&k))
	{	
		for(int i=1;i<=n;i++)
			scanf("%d",&w[i]),e[i].clear();
		for(int i=1;i<n;i++)
			scanf("%d%d",&u,&v),link(u,v);
		fill(vis+1,vis+n+1,0);
		rt=0,son[0]=a=b=n;
		getroot(1,0,n,rt),dnc(rt);
		if(a==n) puts("No solution");
		else printf("%d %d\n",a,b);
	}
}