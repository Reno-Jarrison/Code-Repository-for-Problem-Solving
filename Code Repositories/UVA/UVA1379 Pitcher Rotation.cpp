#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=305;
int dp[2][6][6][6][6],id[maxn];
struct node {	int idx,q; }p[maxn][maxn];
bool operator <(const node& x,const node& y)
{	return x.q>y.q; }
int main()
{
	int t,n,m,g;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&g),g+=10;
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
				scanf("%d",&p[i][j].q),p[i][j].idx=j;
			sort(p[i]+1,p[i]+n+1);
		}
		memset(dp,-0x3f,sizeof(dp));
		dp[0][0][0][0][0]=0;
		int tag=1,ans=0;
		for(int i=1;i<=g;i++,tag^=1)
		{
			memset(dp[tag],-0x3f,sizeof(dp[tag]));
			scanf("%d",&id[i]);
			if(!id[i])
			{
				for(int a=0;a<=5;a++)
					for(int b=0;b<=5;b++)
						for(int c=0;c<=5;c++)
							for(int d=0;d<=5;d++)
							{
								dp[tag][0][a][b][c]=max(dp[tag][0][a][b][c],dp[!tag][a][b][c][d]);
								ans=max(ans,dp[tag][0][a][b][c]);
							}
			}
			else for(int a=0;a<=5;a++)
				for(int b=0;b<=5;b++)
					for(int c=0;c<=5;c++)
						for(int d=0;d<=5;d++)
							for(int cur=1;cur<=5;cur++) 
							{
								int curid=p[id[i]][cur].idx;
								if(i>1&&p[id[i-1]][a].idx==curid) continue;
								if(i>2&&p[id[i-2]][b].idx==curid) continue;
								if(i>3&&p[id[i-3]][c].idx==curid) continue;
								if(i>4&&p[id[i-4]][d].idx==curid) continue;
								dp[tag][cur][a][b][c]=max(dp[tag][cur][a][b][c],dp[!tag][a][b][c][d]+p[id[i]][cur].q);
								ans=max(ans,dp[tag][a][b][c][d]);
							}
		}
		printf("%.2lf\n",ans/100.0);	
	}
}