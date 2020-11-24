#include<iostream>
#include<cstring>
#include<algorithm>
#define maxn 200005
using namespace std;
int s[maxn],o[maxn],psum[maxn],dp[2005];
int main()
{
	ios::sync_with_stdio(false);
	int n,m,k,x,y;
	memset(dp,0x3f,sizeof(dp)); 
	dp[0]=0;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	sort(s+1,s+n+1);
	for(int i=1;i<=k;i++)
		dp[i]=psum[i]=psum[i-1]+s[i];
	for(int i=1;i<=m;i++)
		cin>>x>>y,o[x]=max(o[x],y);
	for(int i=1;i<=k;i++)
		for(int j=0;j<i;j++)
			dp[i]=min(dp[j]+psum[i]-psum[j+o[i-j]],dp[i]);
	cout<<dp[k];
}