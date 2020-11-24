#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int g[maxn][maxn],h[maxn][maxn],l[maxn][maxn],r[maxn][maxn];
int main()
{
	char s[2];
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf("%s",s),g[i][j]=(s[0]=='F');
		for(int i=1;i<=n;i++)
		{
			l[i][1]=1,r[i][m]=m;
			for(int j=2;j<=m;j++)
				l[i][j]=g[i][j-1]?l[i][j-1]:j;
			for(int j=m-1;j;j--)
				r[i][j]=g[i][j+1]?r[i][j+1]:j;
		}
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(!g[i][j]) continue;
				if(i==1) h[i][j]=1;
				else h[i][j]=g[i-1][j]?h[i-1][j]+1:1;
				if(h[i][j]==1) 
				{	ans=max(ans,r[i][j]-l[i][j]+1); continue; }
				l[i][j]=max(l[i][j],l[i-1][j]);
				r[i][j]=min(r[i][j],r[i-1][j]);
				ans=max(ans,h[i][j]*(r[i][j]-l[i][j]+1));
			}
		printf("%d\n",ans*3);
	}
}