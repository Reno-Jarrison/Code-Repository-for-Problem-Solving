#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int a[maxn][maxn];
int main()
{
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		for(int j=1,ok=0;j<=m;j++)
		{
			scanf("%d",&a[i][j]);
			a[i][j]?ok=1:ans+=ok;
		}
		for(int j=m,ok=0;j;j--)
			a[i][j]?ok=1:ans+=ok;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1,ok=0;j<=n;j++)
			a[j][i]?ok=1:ans+=ok;
		for(int j=n,ok=0;j;j--)
			a[j][i]?ok=1:ans+=ok;
	}
	printf("%d\n",ans);
}