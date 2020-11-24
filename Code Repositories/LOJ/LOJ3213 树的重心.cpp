#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=3e5+5;
int siz[maxn],son[maxn][25],son1[maxn],son2[maxn];
int sizx[maxn],sonx[maxn],fat[maxn];
ll ans;
vector<int>e[maxn];
void link(int u,int v)
{	e[u].push_back(v),e[v].push_back(u); }
void dfs1(int u,int f)
{
	siz[u]=1,son1[u]=0,son2[u]=0,fat[u]=f;
	for(int v:e[u])
	{
		if(v==f) continue;
		dfs1(v,u),siz[u]+=siz[v];
		if(siz[v]>siz[son1[u]])
			son2[u]=son1[u],son1[u]=v;
		else if(siz[v]>siz[son2[u]])
			son2[u]=v;
	}
	son[u][0]=son1[u];
	for(int i=1;i<=20;i++)
		son[u][i]=son[son[u][i-1]][i-1];
}
int check(int x,int tot)
{	return max(sizx[sonx[x]],tot-sizx[x])<=tot/2?x:0; }
void dfs2(int u,int f,int tot)
{
	for(int v:e[u])
	{
		if(v==f) continue;
		sizx[u]=tot-siz[v],fat[u]=0,fat[v]=0;
		sonx[u]=(v==son1[u])?son2[u]:son1[u];
		if(sizx[f]>sizx[sonx[u]]) sonx[u]=f;
		son[u][0]=sonx[u];
		for(int i=1;i<=20;i++)
			son[u][i]=son[son[u][i-1]][i-1];
		int ux=u,vx=v;
		for(int i=20;~i;i--)
			if(son[ux][i]&&sizx[u]-sizx[son[ux][i]]<=sizx[u]/2) ux=son[ux][i];
		ans+=check(ux,sizx[u])+check(fat[ux],sizx[u]);
		for(int i=20;~i;i--)
			if(son[vx][i]&&sizx[v]-sizx[son[vx][i]]<=sizx[v]/2) vx=son[vx][i];
		ans+=check(vx,sizx[v])+check(fat[vx],sizx[v]);
		fat[u]=v,dfs2(v,u,tot);
	}
	sizx[u]=siz[u],sonx[u]=son1[u];
	fat[u]=f,son[u][0]=son1[u];
	for(int i=1;i<=20;i++)
		son[u][i]=son[son[u][i-1]][i-1];
}
int main()
{
	int t,n,u,v;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++)
			scanf("%d%d",&u,&v),link(u,v);
		dfs1(1,0);
		for(int i=1;i<=n;i++)
			sizx[i]=siz[i],sonx[i]=son1[i];
		ans=0,dfs2(1,0,n);
		printf("%lld\n",ans);
	}
}