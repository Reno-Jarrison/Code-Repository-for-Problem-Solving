#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e4+5,mod=1e6;
int m,cnt,dp[maxn][50][2]; 
ll ks,s[50],ans;
void dfs(int step,ll sta)
{
	if((sta<<3)&sta) return;
	if(step>=m)
	{
		sta!=ks?s[++cnt]=sta:false;
		return;
	}
	for(ll i=1;i<=3;i++)
		dfs(step+1,sta+(1LL<<(3*step+i)));
}
int main()
{
	int n,k,x;
	cin>>n>>m>>k;
	for(int i=0;i<3*m;i+=3) 
		cin>>x,ks+=1LL<<(i+x);
	if((ks<<3)&ks) { cout<<0; return 0; }
	s[++cnt]=ks,dp[k][1][0]=dp[k][1][1]=1;
	dfs(0,0);
	for(int i=k-1;i;i--)
		for(int j=1;j<=cnt;j++)
			for(int k=1;k<=cnt;k++)
			{
				if(s[j]&s[k]) continue;
				(dp[i][j][0]+=dp[i+1][k][0])%=mod;
			}
	for(int i=k+1;i<=n;i++)
		for(int j=1;j<=cnt;j++)
			for(int k=1;k<=cnt;k++)
			{
				if(s[j]&s[k]) continue;
				(dp[i][j][1]+=dp[i-1][k][1])%=mod;
			}		
	for(int i=1;i<=cnt;i++)
		for(int j=1;j<=cnt;j++)
			(ans+=1LL*dp[1][i][0]*dp[n][j][1])%=mod;
	cout<<ans;
}