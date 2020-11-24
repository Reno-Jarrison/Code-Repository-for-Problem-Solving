#include<bits/stdc++.h>
#define ll long long
#define maxn 2005
int a[maxn],dp[maxn][maxn]; 
using namespace std;
int main()
{
	int n,ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),a[i+n]=a[i];
	for(int i=2;i<=n;i++)
		for(int l=1,r=l+i-1;r<n<<1;l++,r++)
			for(int m=l;m<r;m++)
				dp[l][r]=max(dp[l][r],dp[l][m]+dp[m+1][r]+a[l]*a[r+1]*a[m+1]);
	for(int i=1;i<=n;i++)
		ans=max(ans,dp[i][i+n-1]);
	printf("%d",ans);
}