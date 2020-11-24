#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
int mat[105][15],dp[105][15],path[105][15];
void print_path(int step,int u,int m)
{
	printf("%d",u);
	if(step<m) putchar(' ');
	else { puts(""); return; }
	print_path(step+1,path[step][u-1],m);
}
int main()
{
	int n,m;
	while(~scanf("%d%d",&n,&m))
	{		
		for(int i=0;i<n;i++)
			for(int j=1;j<=m;j++)
				scanf("%d",&mat[j][i]);
		memset(dp,inf,sizeof(dp));
		memset(dp[m+1],0,sizeof(dp[m+1]));
		for(int i=m;i;i--)
			for(int j=0;j<n;j++)
				for(int k=-1;k<=1;k++)
				{
					int idx=(j+k+n)%n,val=dp[i+1][idx]+mat[i][j];
					if(dp[i][j]>val)
						dp[i][j]=val,path[i][j]=idx+1;
					if(dp[i][j]==val) 
						path[i][j]=min(path[i][j],idx+1);
				}
		int id,ans=inf;
		for(int i=0;i<n;i++)
			if(ans>dp[1][i]) ans=dp[1][i],id=i+1;
			else if(ans==dp[1][i]) id=min(id,i+1);
		print_path(1,id,m);
		printf("%d\n",ans);
	}
}
