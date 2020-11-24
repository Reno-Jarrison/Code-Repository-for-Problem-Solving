#include<bits/stdc++.h>
using namespace std;
char s[105];
int dp[105][105];
int main()
{
	cin>>s;
	int len=strlen(s);
	for(int i=0;i<len;i++) dp[i][i]=1;
	for(int i=2;i<=len;i++)
		for(int l=0,r=l+i-1;r<len;l++,r++)
		{
			dp[l][r]=dp[l+1][r-1]+2;
			if(s[l]=='('&&s[r]==')') dp[l][r]-=2;
			else if(s[l]=='['&&s[r]==']') dp[l][r]-=2;
			for(int m=l;m<r;m++)
				dp[l][r]=min(dp[l][r],dp[l][m]+dp[m+1][r]);
		}
	printf("%d",dp[0][len-1]);
}