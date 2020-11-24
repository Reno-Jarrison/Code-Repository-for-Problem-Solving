#include<cstdio>
#define ll long long
using namespace std;
const ll mod=1e8;
ll dp[15][1<<12];
int sta[15];
int main()
{
	int n,m,x;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&x);
			sta[i]|=x,sta[i]<<=1;
		}
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=sta[i-1];;j=(j-1)&sta[i-1])
		{
			if(j&(j<<1)) continue;
			for(int k=sta[i];;k=(k-1)&sta[i])
			{
				if(!(k&(k<<1))&&!(j&k))
					dp[i][k]=(dp[i][k]+dp[i-1][j])%mod;
				if(!k) break;
			}
			if(!j) break;
		}
	ll ans=0;
	for(int i=sta[n];i;i=(i-1)&sta[n])
		ans=(ans+dp[n][i])%mod;
	ans=(ans+dp[n][0])%mod;	
	printf("%lld\n",ans);
}