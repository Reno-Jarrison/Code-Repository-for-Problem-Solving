#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=2e3+5;
const ll mod=998244353;
ll dp[maxn][maxn],cnt[maxn],pow2[maxn]={1};
char s[maxn];
int main()
{
	cin>>(s+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++)
		cnt[i]=cnt[i-1]+(s[i]=='?'),pow2[i]=(pow2[i-1]<<1)%mod;
	for(int i=2;i<=n;i++)
		for(int l=1,r=l+i-1;r<=n;l++,r++)
		{
			ll &x=dp[l][r],p=pow2[cnt[r-1]-cnt[l]];
			x=dp[l+1][r-1];
			if(s[l]==')') x=dp[l+1][r];
			if(s[r]=='(') x=dp[l][r-1];
			if(s[l]=='('&&s[r]==')') x=dp[l+1][r-1]+p;
			if(s[l]=='?'&&s[r]==')') x=dp[l+1][r]+dp[l+1][r-1]+p;
			if(s[l]=='('&&s[r]=='?') x=dp[l][r-1]+dp[l+1][r-1]+p;
			if(s[l]=='?'&&s[r]=='?') x=dp[l][r-1]+dp[l+1][r]+p;
			x%=mod;
		}
	cout<<dp[1][n]<<endl;
}
