#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=3e5+5;
ll a[maxn],s[maxn],dp[maxn],ans;
int main()
{
	ios::sync_with_stdio(false);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],s[i]=s[i-1]+a[i];
	for(int i=0;i<=n;i++)
	{
		dp[i]=i>=m?max(0LL,dp[i-m]+s[i]-s[i-m]-k):0;
		ans=max(ans,dp[i]);
		for(int j=1;j<=m&&i+j<=n;j++)
			ans=max(ans,dp[i]+s[i+j]-s[i]-k);
	}
	cout<<ans;
}
