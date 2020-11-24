#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int maxn=505;
int h[maxn],idx[maxn][2],cnt[2],mat[maxn];
char sex[2],musi[maxn][105],name[maxn][105];
bool e[maxn][maxn],vis[maxn];
bool link(int u,int v)
{	return abs(h[u]-h[v])<=40&&!strcmp(musi[u],musi[v])&&strcmp(name[u],name[v]); }
bool dfs(int u)
{
	for(int v=1;v<=cnt[1];v++)
	{
		if(!e[u][v]||vis[v]) continue;
		vis[v]=true;
		if(!mat[v]||dfs(mat[v]))
		{	mat[v]=u; return true; }		
	}
	return false;
}
int hungary()
{
	memset(mat,0,sizeof(mat));
	int ans=0;
	for(int i=1;i<=cnt[0];i++)
		memset(vis,0,sizeof(vis)),ans+=dfs(i);
	return ans;
}
int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		cnt[0]=cnt[1]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%s%s%s",&h[i],sex,musi[i],name[i]);
			int id=(sex[0]=='M');
			idx[++cnt[id]][id]=i;
		}
		memset(e,0,sizeof(e));
		for(int i=1;i<=cnt[0];i++)
			for(int j=1;j<=cnt[1];j++)
				if(link(idx[i][0],idx[j][1])) e[i][j]=true;
		printf("%d\n",n-hungary());
	}
}