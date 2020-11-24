#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
const int maxn=505;
int time[maxn],x[maxn][2],y[maxn][2],mat[maxn];
bool e[maxn][maxn],vis[maxn];
int gettime(int u,int v)
{	return abs(x[u][1]-x[v][0])+abs(y[u][1]-y[v][0]); }
bool dfs(int u,int n)
{
	for(int v=1;v<=n;v++)
	{
		if(!e[u][v]||vis[v]) continue;
		vis[v]=true;
		if(!mat[v]||dfs(mat[v],n))
		{	mat[v]=u; return true; }
	}
	return false;
}
int hungary(int n)
{
	memset(mat,0,sizeof(mat));
	int ans=0;
	for(int i=1;i<=n;i++)
		memset(vis,0,sizeof(vis)),ans+=dfs(i,n);
	return ans;
}
int main()
{
	int t,n,h,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d:%d",&h,&m);
			time[i]=h*60+m;			
			for(int j=0;j<=1;j++)
				scanf("%d%d",&x[i][j],&y[i][j]);
		}
		memset(e,0,sizeof(e));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j&&time[i]+gettime(i,i)+gettime(i,j)<time[j]) 
					e[i][j]=true;
		printf("%d\n",n-hungary(n));
	}
}