#include<cstdio>
#include<cstring>
using namespace std;
int g[10][10],vis[10],n,ans;
void dfs(int step,int k)
{
	if(step>n)
	{	ans+=!k; return; }
	dfs(step+1,k);
	if(!k) return;
	for(int i=1;i<=n;i++)
		if(!g[step][i]&&!vis[i])
			vis[i]=1,dfs(step+1,k-1),vis[i]=0;
}
int main()
{
	int k;
	while(scanf("%d%d",&n,&k)&&n!=-1)
	{
		char s[10];
		memset(g,0,sizeof(g)),ans=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
		{
			scanf("%s",s+1);
			for(int j=1;j<=n;j++)
				if(s[j]=='.') g[i][j]=1;
		}
		dfs(1,k);
		printf("%d\n",ans);
	}
}