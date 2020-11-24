#include<bits/stdc++.h>
using namespace std;
const int maxn=1<<13,mod=1e8;
int ans,s[15],dp[15][maxn];
int main()
{
	int n,m,bit,maxm;
	cin>>n>>m,maxm=1<<m;
	for(int i=1;i<=n;i++)
		for(int j=0;j<m;j++)
			cin>>bit,s[i]+=bit<<j;
	for(int i=1;i<=n;i++)
		for(int j=0;j<maxm;j++)
		{
			if(j&(j<<1)) continue;
			if(j&(~s[i])) continue;
			if(i==1) dp[i][j]=1;
			else for(int k=0;k<maxm;k++)
			{
				if(j&k) continue; 
				(dp[i][j]+=dp[i-1][k])%=mod;
			}
		}
	for(int i=0;i<maxm;i++) (ans+=dp[n][i])%=mod;
	cout<<ans;
}