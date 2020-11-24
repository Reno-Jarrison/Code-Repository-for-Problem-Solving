#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e3+5;
const ll mod=1e9+7;
ll dp[maxn]={0,1};
int main()
{
	for(int i=2;i<=1000;i++)
		for(int j=1;j<i;j++) if((i-1)%j==0) 
			dp[i]=(dp[i]+dp[(i-1)/j])%mod;
	int n,ks=0;
	while(~scanf("%d",&n))
		printf("Case %d: %lld\n",++ks,dp[n]);
}