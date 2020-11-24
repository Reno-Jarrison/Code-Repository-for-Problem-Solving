#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e3+5;
const ll mod=1e9+7;
ll dp1[maxn],dp2[maxn];
int main()
{
	int n;
	scanf("%d",&n);
	dp1[0]=dp2[0]=1;
	for(int i=1;i<=n;i++)
	{
		if(i>=3) dp1[i]=dp2[i-3];
		dp2[i]=(dp2[i-1]+dp1[i])%mod;
	}
	printf("%lld\n",dp1[n]);
}