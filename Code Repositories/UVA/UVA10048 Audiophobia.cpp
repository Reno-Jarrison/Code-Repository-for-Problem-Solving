#include<cstdio>
#include<cstring>
#include<algorithm> 
using namespace std;
const int maxn=105,inf=0x3f3f3f3f;
int dist[maxn][maxn];
void floyd(int n)
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dist[i][j]=min(dist[i][j],max(dist[i][k],dist[k][j]));
}
int main()
{
	int c,s,q,u,v,w,cases=0,first=0;
	while(scanf("%d%d%d",&c,&s,&q)&&c&&s&&q)
	{
		memset(dist,inf,sizeof(dist));
		for(int i=1;i<=s;i++)
		{
			scanf("%d%d%d",&u,&v,&w);
			dist[u][v]=dist[v][u]=w;
		}
		floyd(c);
		if(first++) puts("");
		printf("Case #%d\n",++cases);
		for(int i=1;i<=q;i++)
		{
			scanf("%d%d",&u,&v);
			if(dist[u][v]==inf) printf("no path\n");
			else printf("%d\n",dist[u][v]);
		}
	}
}