#include<bits/stdc++.h>
#define lowbit(x) (x)&(-x)
using namespace std;
const int maxn=1e5+5;
vector<int>e[maxn],bound[maxn];
int a[maxn],lg2[maxn],tree[maxn],ans[maxn];
int rt[maxn],dep[maxn],fat[maxn][20];
void getlg2(int n)
{	
	for(int i=2;i<=n;i++) 
		lg2[i]=lg2[i>>1]+1;
}
void update(int x,int val)
{	while(x<maxn) tree[x]+=val,x+=lowbit(x); }
int query(int x)
{
	int ans=0;
	while(x) ans+=tree[x],x-=lowbit(x);
	return ans;
}
void dfs1(int u,int f)
{
	dep[u]=dep[f]+1,fat[u][0]=f;
	for(int i=1;(1<<i)<=dep[u];i++)
		fat[u][i]=fat[fat[u][i-1]][i-1];
	for(int v:e[u]) dfs1(v,u);
}
void dfs2(int u)
{
	for(int x:bound[u])
		update(x,1);
	ans[u]=query(a[u]);
	for(int v:e[u]) dfs2(v);
	for(int x:bound[u]) 
		update(x,-1);
}
int main()
{
	int n,m,f,x,l,r;
	getlg2(1e5);
	scanf("%d%d",&n,&m);
	scanf("%d%d",&a[1],&f);
	for(int i=2;i<=n;i++)
		scanf("%d%d",&a[i],&f),e[f].push_back(i);
	a[0]=0x3f3f3f3f,dfs1(1,0);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&x,&l,&r);
		for(int j=lg2[dep[x]];j>=0;j--)
			if(a[fat[x][j]]<=r) x=fat[x][j];
		bound[x].push_back(l);
	}
	dfs2(1);
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
}