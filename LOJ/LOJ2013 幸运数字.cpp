#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
const int maxn=2e4+5;
ll g[maxn];
vector<int>e[maxn];
int dep[maxn],fat[maxn][20],lg2[maxn]={-1};
struct libasis
{
	ll bas[62];
	void init(){ memset(bas,0,sizeof(bas)); }
	void insert(ll x)
	{
		if(!x) return;
		for(int i=60;i>=0;i--)
			if(x&(1LL<<i))
			{
				if(bas[i]) x^=bas[i];
				else { bas[i]=x; return; }
			}
	}
	ll getmax()
	{
		ll ans=0;
		for(int i=60;i>=0;i--)
			if(!(ans&(1LL<<i))) ans^=bas[i];
		return ans;
	}
}lb[maxn][20];
void getlg2()
{	for(int i=1;i<=maxn-5;i++) lg2[i]=lg2[i>>1]+1; }
libasis merge(const libasis& x,const libasis& y)
{
	libasis tmp=x;
	for(int i=60;i>=0;i--)
		if(y.bas[i]) tmp.insert(y.bas[i]);
	return tmp;
}
void dfs(int u,int f,int d)
{
	dep[u]=d,fat[u][0]=f,lb[u][0].insert(g[f]);
	for(int i=1;(1<<i)<=d;i++)
	{
		int nxt=fat[u][i-1];
		lb[u][i]=merge(lb[u][i-1],lb[nxt][i-1]);
		fat[u][i]=fat[nxt][i-1];
	}
	for(int i=0;i<(int)e[u].size();i++)
	{
		int v=e[u][i];
		if(v==f) continue;
		dfs(v,u,d+1);
	}
}
ll query(int x,int y)
{
	libasis tmp;
	tmp.init();
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y])
	{
		int step=lg2[dep[x]-dep[y]];
		tmp=merge(tmp,lb[x][step]);
		x=fat[x][step];
	}
	if(x==y) tmp.insert(g[x]);
	else 
	{
		for(int i=lg2[dep[x]];i>=0;i--)
			if(fat[x][i]!=fat[y][i])
			{
				tmp=merge(tmp,merge(lb[x][i],lb[y][i]));
				x=fat[x][i],y=fat[y][i];
			}
		tmp=merge(tmp,merge(lb[x][0],lb[y][0]));
	}
	return tmp.getmax();
}
int main()
{
	getlg2();
	int n,q,u,v;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%lld",&g[i]),lb[i][0].insert(g[i]);
	for(int i=1;i<n;i++)
	{
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1,0,0);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&u,&v);
		printf("%lld\n",query(u,v));
	}
}