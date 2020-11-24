#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
const ll mod=100003;
int a[maxn];
ll dp[maxn];
vector<int>vec[maxn];
ll qpow(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%mod;
		a=a*a%mod,b>>=1;
	}
	return ans;
}
ll inv(ll x) { return qpow(x,mod-2); }
int main()
{
	int n,k,cnt=0;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j+=i)
			vec[j].push_back(i);
	for(int i=n;i;i--)
	{
		if(!a[i]) continue;
		cnt++;
		for(int j=0;j<vec[i].size();j++) 
			a[vec[i][j]]^=1;
	}
	for(int i=n;i>k;i--)
		dp[i]=(dp[i+1]*(n-i)%mod+n)*inv(i)%mod;
	ll ans=k;
	for(int i=k+1;i<=cnt;i++)
		ans=(ans+dp[i])%mod;
	if(cnt<=k) ans=cnt;
	for(int i=1;i<=n;i++)
		ans=ans*i%mod;
	printf("%lld",ans);
}