#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=705,mod=1e9+7;
char s[maxn];
int num[maxn];
ll dp[maxn][11],f[maxn][maxn][10][2];
void add(ll& a,int b)
{	a=(a+b)%mod; }
ll dfs(int pos,int cnt,int cur,bool lim)
{
	if(cnt<0) return 0;
	if(!pos) return !cnt;
	if(~f[pos][cnt][cur][lim])
		return f[pos][cnt][cur][lim];
	int bound=lim?num[pos]:9;
	ll ans=0;
	for(int i=0;i<=bound;i++)
		add(ans,dfs(pos-1,cnt-(i>=cur),cur,lim&&i==bound));
	return f[pos][cnt][cur][lim]=ans;
}
ll solve()
{
	int len=strlen(s);
	for(int i=1;i<=len;i++)
		num[i]=s[len-i]-'0';
	memset(f,-1,sizeof(f));
	for(int i=1;i<=len;i++)
		for(int j=0;j<=9;j++)
			dfs(len,i,j,true);
	for(int j=0;j<=9;j++)
	{
		for(int i=1;i<=len;i++)
		{
			ll tmp=0;
			if(~f[len][i][j][0]) 
				add(tmp,f[len][i][j][0]);
			if(~f[len][i][j][1]) 
				add(tmp,f[len][i][j][1]);
			add(dp[1][j],tmp),add(dp[i+1][j],mod-tmp);
		}
		for(int i=1;i<=len;i++)
			add(dp[i][j],dp[i-1][j]);
	}
	ll ans=0,pow10=1;
	for(int i=1;i<=len;i++)
	{
		for(int j=1;j<=9;j++)
			add(ans,(dp[i][j]-dp[i][j+1]+mod)%mod*pow10%mod*j%mod);
		pow10=pow10*10%mod;
	}
	return ans;
}
int main()
{
	scanf("%s",s);
	printf("%lld\n",solve());
}