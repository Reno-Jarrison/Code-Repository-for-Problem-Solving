#include<cstdio>
#include<algorithm>
#define ll long long
using namespace std;
const int maxn=2e5+5;
ll a,dp[5];
char s[maxn];
int idx[130];
int main()
{
	int n;
	scanf("%d%s",&n,s+1);
	idx['h']=1,idx['a']=2;
	idx['r']=3,idx['d']=4;
	for(int i=1;i<=n;i++)
	{	
		scanf("%lld",&a);
		if(!idx[s[i]]) continue;
		int id=idx[s[i]];
		dp[id]=min(dp[id],dp[id-1]);
		dp[id-1]=dp[id-1]+a;
	}	
	ll ans=1e18;
	for(int i=0;i<4;i++)
		ans=min(ans,dp[i]);
	printf("%lld",ans);
}