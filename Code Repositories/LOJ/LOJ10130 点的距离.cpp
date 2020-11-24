#include<cstdio>
#include<vector>
using namespace std;
const int maxn=1e5+5;
int lg2[maxn],dep[maxn],fat[maxn][25];
vector<int>e[maxn];
void getlg2()
{	for(int i=2;i<=maxn-5;i++) lg2[i]=lg2[i>>1]+1; }
void dfs(int u,int f)
{
	dep[u]=dep[f]+1;
	fat[u][0]=f;
	for(int i=1;i<=20;i++)
		fat[u][i]=fat[fat[u][i-1]][i-1];
	for(int i=0;i<(int)e[u].size();i++)
	{
		int v=e[u][i];
		if(v!=f) dfs(v,u);
	}
}

int getlca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int i=20;i>=0;i--)
		if(dep[x]-dep[y]>=(1<<i))
			x=fat[x][i];
	if(x==y) return x;
	for(int i=20;i>=0;i--)
		if(fat[x][i]!=fat[y][i])
			x=fat[x][i],y=fat[y][i];
	return fat[x][0];
}
int query(int x,int y)
{
	return dep[x]+dep[y]-dep[getlca(x,y)]*2;
}
int main()
{
	int n,q,x,y;
	getlg2();
	scanf("%d",&n);
	for(int i=1;i<n;i++)
		scanf("%d%d",&x,&y),e[x].push_back(y),e[y].push_back(x);
	dfs(1,0);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
		scanf("%d%d",&x,&y),printf("%d\n",query(x,y));
}