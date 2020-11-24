#include<cstdio>
#include<cstring>
using namespace std;
int n,m,g[20][20],opt[20][20],ans[20][20],mnv=300;
void flip(int r,int c)
{
	for(int i=-1;i<=1;i++)
		g[r+i][c]^=1;
	g[r][c-1]^=1,g[r][c+1]^=1;
}
bool check()
{
	for(int i=1;i<=m;i++)
		if(g[n][i]) return false;
	return true;
}
void dfs(int r,int c,int tot)
{
	if(tot>=mnv) return;
	if(c>m) r++,c=1;
	if(r>n)
	{	if(check()) mnv=tot,memcpy(ans,opt,sizeof(ans)); return; }
	if(!g[r-1][c]) dfs(r,c+1,tot);
	else
	{
		flip(r,c),opt[r][c]=1;
		dfs(r,c+1,tot+1);
		flip(r,c),opt[r][c]=0;
	}
}
void solve(int pos,int cnt)
{
	if(pos>m)
	{	dfs(2,1,cnt); return; }
	solve(pos+1,cnt);
	flip(1,pos),opt[1][pos]=1;
	solve(pos+1,cnt+1);
	flip(1,pos),opt[1][pos]=0;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&g[i][j]);
	solve(1,0);
	if(mnv==300) puts("IMPOSSIBLE");
	else
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				printf("%d%c",ans[i][j],j==m?'\n':' ');
	}
}