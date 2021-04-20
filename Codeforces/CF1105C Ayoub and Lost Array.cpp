#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
ll cnt[3],dp[2][3];
int main()
{
	int n,l,r;
	scanf("%d%d%d",&n,&l,&r);
	for(int i=0;i<3;i++)
		cnt[i]=(r+3-i)/3-(l-1+3-i)/3;
	dp[0][0]=1;
	int tag=0;
	for(int i=1;i<=n;i++,tag^=1)
		for(int j=0;j<3;j++)
		{
			dp[tag^1][j]=0;	
			for(int k=0;k<3;k++)
				dp[tag^1][j]+=dp[tag][k]*cnt[(j-k+3)%3];
			dp[tag^1][j]%=mod;	
		}
	printf("%lld\n",dp[tag][0]);
}