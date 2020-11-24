#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5,mod=998244353;
ll dp[maxn],s[maxn];
int main()
{
	int n,k,l[15],r[15];
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
		scanf("%d%d",&l[i],&r[i]);
	dp[1]=s[1]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=k;j++)
		{
			if(i<=l[j]) continue;
			ll val=(s[i-l[j]]-(i>r[j]?s[i-r[j]-1]:0)+mod)%mod;			
			dp[i]=(dp[i]+val)%mod;
		}
		s[i]=(s[i-1]+dp[i])%mod;
	}
	printf("%lld\n",dp[n]);
}