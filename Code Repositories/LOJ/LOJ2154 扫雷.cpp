#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e4+5;
ll dp[maxn][4];
int cnt[8]={0,1,1,2,1,2,2,3};
int main()
{
	int n,x;
	cin>>n;
	dp[0][0]=dp[0][1]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		for(int j=0;j<8;j++)
			if(cnt[j]==x)
				dp[i][j&3]+=dp[i-1][j>>1];
	}
	cout<<dp[n][0]+dp[n][2];
}