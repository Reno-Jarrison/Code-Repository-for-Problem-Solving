#include<bits/stdc++.h>
#define ll long long
#define maxn 2005
#define inf 0x3f3f3f3f
int ap[maxn],bp[maxn],as[maxn],bs[maxn];
int dp[maxn][maxn],q[maxn];
using namespace std;
inline bool check(int i,int w,int j,int k,int *p)
{	return dp[i-w-1][j]+j*p[i]<=dp[i-w-1][k]+k*p[i]; }
int main()
{
	ios::sync_with_stdio(false);
	int t,p,w,ans=-inf;
	cin>>t>>p>>w;
	for(int i=1;i<=t;i++)
		cin>>ap[i]>>bp[i]>>as[i]>>bs[i];
	memset(dp,-0x3f,sizeof(dp));
	for(int i=1;i<=t;i++)
	{
		for(int j=0;j<=p;j++)
		{
			if(j<=as[i]) dp[i][j]=-j*ap[i];
			dp[i][j]=max(dp[i][j],dp[i-1][j]);
		}
		if(i<=w) continue;
		for(int j=0,h=1,t=0;j<=p;j++)
		{
			if(h<=t&&q[h]<j-as[i]) h++;
			while(h<=t&&check(i,w,q[t],j,ap)) t--;
			q[++t]=j;
			dp[i][j]=max(dp[i][j],dp[i-w-1][q[h]]-(j-q[h])*ap[i]);
		}
		for(int j=p,h=1,t=0;j>=0;j--)
		{
			if(h<=t&&q[h]>j+bs[i]) h++;
			while(h<=t&&check(i,w,q[t],j,bp)) t--;
			q[++t]=j;
			dp[i][j]=max(dp[i][j],dp[i-w-1][q[h]]+(q[h]-j)*bp[i]);
		}
	}
	for(int i=0;i<=p;i++) 
		ans=max(ans,dp[t][i]);
	cout<<ans;
}