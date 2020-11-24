#include<bits/stdc++.h>
using namespace std;
int n,root[35][35];
long long dp[35][35];
void traverse(int left,int right)
{
	if(left>right)
		return;
	int r=root[left][right];
	cout<<r<<" ";
	if(left==right)
		return;
	traverse(left,r-1);
	traverse(r+1,right);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>dp[i][i],dp[i+1][i]=1,root[i][i]=i;
	for(int i=1;i<n;i++)
		for(int j=1,k=i+1;k<=n;j++,k++)   
		{
			dp[j][k]=dp[j][j]+dp[j+1][k]; 
			root[j][k]=j;
			for(int r=j+1;r<=k;r++)      
				if(dp[j][r-1]*dp[r+1][k]+dp[r][r]>dp[j][k])
					dp[j][k]=dp[j][r-1]*dp[r+1][k]+dp[r][r],root[j][k]=r;
		}
	cout<<dp[1][n]<<endl;
	traverse(1,n);
}