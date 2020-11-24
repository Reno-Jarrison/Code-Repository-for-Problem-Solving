#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e3+5;
int mat[maxn]; 
bool e[maxn][maxn],vis[maxn],tag[maxn][2];
bool dfs1(int u,int n2)
{
	for(int v=1;v<=n2;v++)
	{
		if(!e[u][v]||vis[v]) continue;
		vis[v]=true;
		if(!mat[v]||dfs1(mat[v],n2))
		{	mat[v]=u; return true; }
	}
	return false;
}
void dfs2(int u,int n2)
{
	tag[u][0]=true;
	for(int v=1;v<=n2;v++)
		if(e[u][v]&&!tag[v][1]&&mat[v])
			tag[v][1]=true,dfs2(mat[v],n2);	
}
int hungary(int n1,int n2)
{
	memset(mat,0,sizeof(mat));
	int ans=0;
	for(int i=1;i<=n1;i++)
		memset(vis,0,sizeof(vis)),ans+=dfs1(i,n2);
	return ans;
}
int main()
{
	int r,c,n,u,v;
	while(scanf("%d%d%d",&r,&c,&n)&&r)
	{
		memset(e,0,sizeof(e));
		for(int i=1;i<=n;i++)
			scanf("%d%d",&u,&v),e[u][v]=true;
		printf("%d",hungary(r,c));
		memset(vis,0,sizeof(vis));
		memset(tag,0,sizeof(tag));
		for(int i=1;i<=c;i++)
			vis[mat[i]]=true;
		for(int i=1;i<=r;i++)
			if(!vis[i]) dfs2(i,r);
		for(int i=1;i<=r;i++)
			if(!tag[i][0]) printf(" r%d",i);
		for(int i=1;i<=c;i++)
			if(tag[i][1]) printf(" c%d",i);
		puts("");
	}
}