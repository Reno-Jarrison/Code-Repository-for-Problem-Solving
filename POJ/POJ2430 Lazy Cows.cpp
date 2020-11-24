#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int maxn=1e3+5,inf=0x3f3f3f3f;
int dp[maxn][maxn][4],p[maxn];
map<int,int>mp;
void update(int& cur,int val)
{	cur=min(cur,val); }
int main()
{
	int n,k,b,x;
	scanf("%d%d%d",&n,&k,&b);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&p[i]);
		mp[p[i]]|=(1<<(x-1));
	}
	sort(p+1,p+n+1);
	int uni=unique(p+1,p+n+1)-p-1;
	memset(dp,inf,sizeof(dp));
	memset(dp[0][0],0,sizeof(dp[0][0]));
	for(int i=1;i<=uni;i++)
		for(int j=1;j<=k;j++)
		{
			int dis=p[i]-p[i-1];
			if(mp[p[i]]==1)
			{
				update(dp[i][j][0],dp[i-1][j][0]+dis);
				update(dp[i][j][0],dp[i-1][j][3]+dis);
				for(int l=0;l<4;l++)
					update(dp[i][j][0],dp[i-1][j-1][l]+1);
			}
			if(mp[p[i]]==2)
			{
				update(dp[i][j][1],dp[i-1][j][1]+dis);
				update(dp[i][j][1],dp[i-1][j][3]+dis);
				for(int l=0;l<4;l++)
					update(dp[i][j][1],dp[i-1][j-1][l]+1);
			}
			update(dp[i][j][2],dp[i-1][j][2]+dis*2);
			if(j>=2)
			{
				update(dp[i][j][3],dp[i-1][j][3]+dis*2);
				update(dp[i][j][3],dp[i-1][j-1][0]+dis+1);
				update(dp[i][j][3],dp[i-1][j-1][1]+dis+1);
			}
			for(int l=0;l<4;l++)
			{
				update(dp[i][j][2],dp[i-1][j-1][l]+2);
				if(j>=2) update(dp[i][j][3],dp[i-1][j-2][l]+2);
			}
		}
	int ans=inf;
	for(int i=0;i<4;i++)
		update(ans,dp[uni][k][i]);
	printf("%d\n",ans);
}