#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int dp[405][1<<10];
bool pld[12][1<<11];
bool check(int len,int s)
{
	int tmp[12];
	for(int i=0;i<len;i++)
		tmp[i]=s&1,s>>=1;
	for(int i=0;i<len/2;i++)
		if(tmp[i]!=tmp[len-i-1]) return false;
	return true;
}
int main()
{
	int t,n,k;
	scanf("%d",&t);
	for(int i=0;i<(1<<11);i++)
		for(int j=1;j<=11;j++)
			pld[j][i]=check(j,i);
	while(t--)
	{
		scanf("%d%d",&n,&k);
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for(int i=0;i<n;i++)
			for(int j=0;j<(1<<min(i+1,k));j++)
			{
				if(!dp[i][j]) continue;
				for(int x=0;x<=1;x++)
				{
					int s=(j<<1|x)&((1<<k)-1);
					if(i+1>=k&&pld[k][s]) continue;
					if(i+1>=k+1&&pld[k+1][j<<1|x]) continue;
					dp[i+1][s]=(dp[i+1][s]+dp[i][j])%mod;
				}
			}
		int ans=0;
		for(int i=0;i<(1<<k);i++)
			ans=(ans+dp[n][i])%mod;
		printf("%d\n",ans);
	}
}