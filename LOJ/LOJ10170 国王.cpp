#include<bits/stdc++.h>
#define ll long long
#define maxn 1500
using namespace std;
int n,c,cnt,s[maxn],num[maxn];
ll dp[15][maxn][105],ans;
void dfs(int step,int sta,int sum)
{
	if(step>=n)
	{
		s[++cnt]=sta,num[cnt]=sum;
		dp[1][cnt][sum]=1;
		return;
	}
	dfs(step+1,sta,sum);
	dfs(step+2,sta+(1<<step),sum+1);
}
int main()
{
	cin>>n>>c;
	dfs(0,0,0);
	for(int i=2;i<=n;i++)
		for(int j=1;j<=cnt;j++)
			for(int k=1;k<=cnt;k++)
			{
				if(s[j]&s[k]) continue;
				if(s[j]&(s[k]<<1)) continue;
				if(s[k]&(s[j]<<1)) continue;
				for(int m=num[j];m<=c;m++) 
					dp[i][j][m]+=dp[i-1][k][m-num[j]];
			}
	for(int i=1;i<=cnt;i++)
		ans+=dp[n][i][c];
	cout<<ans;
}