#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=105;
ll s[maxn],dp[maxn][maxn];
int main()
{
	int n;
	while(cin>>n&&n)
	{
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++) 
			cin>>dp[i][i],s[i]=s[i-1]+dp[i][i];
		for(int i=2;i<=n;i++)
			for(int j=1,k=i;k<=n;j++,k++)
			{
				ll mins=1e10;
				for(int pt=j;pt<=k;pt++)
					mins=min(mins,min(dp[j][pt],dp[pt][k]));
				dp[j][k]=s[k]-s[j-1]-mins;
			}
		cout<<(dp[1][n]<<1)-s[n]<<endl;
	}
}
