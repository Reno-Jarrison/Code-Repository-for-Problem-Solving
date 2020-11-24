#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6+5;
ll dp[maxn],n;
int main()
{
	for(ll i=3;i<maxn;i++)
		dp[i]=dp[i-1]+((i-1)*(i-2)/2-i/2+1)/2;
	while(scanf("%lld",&n)&&n>2)
		printf("%lld\n",dp[n]);
}