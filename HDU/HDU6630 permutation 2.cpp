#include<cstdio>
#define ll long long
using namespace std;
const int maxn=1e5;
ll dp[maxn+5],dpx[maxn+5],mod=998244353;
int main()
{
	int t,n,x,y;
	scanf("%d",&t);
	dp[0]=0,dpx[0]=dp[1]=dpx[1]=dp[2]=dpx[2]=1;
	for(int i=3;i<=maxn;i++)
	{
		dp[i]=(dp[i-1]+dp[i-3])%mod;
		dpx[i]=(dpx[i-1]+dpx[i-3])%mod;
	}
	while(t--)
	{
		scanf("%d%d%d",&n,&x,&y);
		ll ans;
		if(x==1&&y==n) ans=dpx[y-x];
		else if(x==1) ans=dpx[y-x-1];
		else if(y==n) ans=dp[y-x];
		else ans=dp[y-x-1];
		printf("%lld\n",ans); 
	} 
}
