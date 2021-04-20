#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
char s[maxn][maxn];
int main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)
			scanf("%s",s[i]+1);
		if(m%2==0&&n==2&&s[1][2]!=s[2][1])
		{	puts("NO"); continue; }
		puts("YES");
		if(m&1)
		{
			for(int i=1;i*2<=m+1;i++)
				printf("1 2%c",i*2==m+1?'\n':' ');
			continue;
		}
		int ok=0;
		for(int i=1;i<=n&&!ok;i++)
			for(int j=i+1;j<=n&&!ok;j++)
				if(s[i][j]==s[j][i])
				{
					for(int k=1;k*2<=m;k++)
						printf("%d %d ",i,j);
					printf("%d\n",i),ok=1;
				}
		if(ok) continue;
		else
		{
			int a,b,c;
			if(s[1][2]==s[2][3]) a=1,b=2,c=3;
			if(s[2][3]==s[3][1]) a=2,b=3,c=1;
			if(s[3][1]==s[1][2]) a=3,b=1,c=2;
			if((m/2)&1)
			{
				for(int i=1;i*2<=m/2-1;i++)
					printf("%d %d ",a,b);
				printf("%d %d %d ",a,b,c);
				for(int i=1;i*2<=m/2-1;i++)
					printf("%d %d%c",b,c,i*2==m/2-1?'\n':' ');
			}
			else
			{
				for(int i=1;i*2<=m/2;i++)
					printf("%d %d ",b,a);
				printf("%d ",b);
				for(int i=1;i*2<=m/2;i++)
					printf("%d %d%c",c,b,i*2==m/2?'\n':' ');
			}
		}
	}
}