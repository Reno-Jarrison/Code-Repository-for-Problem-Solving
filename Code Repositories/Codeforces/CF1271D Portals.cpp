#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e3+5;
int a[maxn],b[maxn],c[maxn],idx[maxn],dp[maxn][maxn];
vector<int>p[maxn];
int main()
{
	int n,m,tot,u,v;
	cin>>n>>m>>tot;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i]>>c[i],idx[i]=i;
	for(int i=1;i<=m;i++)
		cin>>u>>v,idx[v]=max(idx[v],u);
	for(int i=1;i<=n;i++)
		p[idx[i]].push_back(i);
	memset(dp,-1,sizeof(dp));
	dp[0][tot]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i];j+b[i]<maxn;j++)
			dp[i][j+b[i]]=dp[i-1][j];
		for(int j:p[i]) for(int k=1;k<maxn;k++) 
			if(dp[i][k]!=-1)
				dp[i][k-1]=max(dp[i][k-1],dp[i][k]+c[j]);
	}
	int ans=-1;
	for(int i=0;i<maxn;i++)
		ans=max(ans,dp[n][i]);
	cout<<ans;
}