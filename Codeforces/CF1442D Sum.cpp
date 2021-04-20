#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=3e3+5;
int siz[maxn],n,k,x;
ll s[maxn][maxn],dp[maxn],ans;
void solve(int l,int r)
{
	if(l==r)
	{
		for(int i=0;i<=siz[l];i++)
			ans=max(ans,dp[k-i]+s[l][i]);
		return;
	}
	int mid=(l+r)>>1;
	vector<ll>buf;
	for(int i=0;i<=n;i++)
		buf.push_back(dp[i]);
	for(int i=l;i<=mid;i++)
		for(int j=k;j>=siz[i];j--)
			dp[j]=max(dp[j],dp[j-siz[i]]+s[i][siz[i]]);
	solve(mid+1,r);
	for(int i=0;i<=n;i++)
		dp[i]=buf[i];
	for(int i=mid+1;i<=r;i++)
		for(int j=k;j>=siz[i];j--)
			dp[j]=max(dp[j],dp[j-siz[i]]+s[i][siz[i]]);
	solve(l,mid);
}
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&siz[i]);
		for(int j=1;j<=siz[i];j++)
		{
			scanf("%d",&x);
			if(j<=k) s[i][j]=s[i][j-1]+x;
		}
		siz[i]=min(siz[i],k);
	}
	solve(1,n);
	printf("%lld\n",ans);
}