#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn],dp[maxn][6];
int main()
{
	int t,n,k,z;
	cin>>t;
	while(t--)
	{
		cin>>n>>k>>z;
		for(int i=1;i<=n;i++)
			cin>>a[i],memset(dp[i],0,sizeof(dp[i]));
		int ans=0;
		for(int i=1;i<=k+1;i++)
			for(int j=0;j<=z&&i+j*2<=k+1;j++)
			{
				dp[i][j]=dp[i-1][j]+a[i];
				if(j) dp[i][j]=max(dp[i][j],dp[i][j-1]+a[i]+a[i+1]);
				ans=max(ans,dp[i][j]);
			}
		cout<<ans<<endl;
	}
}