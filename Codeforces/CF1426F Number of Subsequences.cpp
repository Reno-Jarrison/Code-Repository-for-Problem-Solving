#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e5+5,mod=1e9+7;
char s[maxn];
ll dp[maxn][3];
void update(ll& cur,ll val)
{	cur=(cur+val)%mod; }
int main()
{
	int n;
	scanf("%d%s",&n,s+1);
	ll tot=1;
	for(int i=1;i<=n;i++)
	{
		int tag=s[i]=='?';
		for(int j=0;j<3;j++)
			dp[i][j]=dp[i-1][j]*(tag?3:1)%mod;
		if(s[i]=='a'||tag)
			update(dp[i][0],tot);
		if(s[i]=='b'||tag)
			update(dp[i][1],dp[i-1][0]);
		if(s[i]=='c'||tag)
			update(dp[i][2],dp[i-1][1]);
		if(tag) tot=tot*3%mod;
	}
	printf("%lld\n",dp[n][2]);
}