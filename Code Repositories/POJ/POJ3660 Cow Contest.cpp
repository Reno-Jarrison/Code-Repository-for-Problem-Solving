#include<cstdio>
using namespace std;
int e[105][105];
void floyd(int n)
{
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				e[i][j]|=e[i][k]&&e[k][j];
}
int main()
{
	int n,m,u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&u,&v),e[u][v]=1;
	floyd(n);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
			if(i!=j&&(e[i][j]||e[j][i])) cnt++;
		if(cnt==n-1) ans++;
	}
	printf("%d\n",ans);
}