#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e6+5,mod=1e9+7;
ll dp[maxn][2];
int main()
{
	for(int i=3;i<maxn;i++)
	{
		dp[i][1]=(dp[i-2][0]*2+dp[i-1][0]+1)%mod;
		dp[i][0]=dp[i][1]+i%3-1;
	}
	int t,n;
	cin>>t;
	while(t--)
		cin>>n,cout<<max(dp[n][0],dp[n][1])*4%mod<<endl;
}