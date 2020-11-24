#include<cstdio>
#define ll long long
using namespace std;
const int maxn=5e5+5;
ll mod=1e9+7;
ll dp[maxn],p,q,r,s,a;
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
ll inv(ll a)
{	return qpow(a,mod-2); }
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,Q,x;
		scanf("%d%d",&n,&Q);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld%d%lld",&r,&s,&x,&a);
			p=r*inv(s)%mod;
			q=(s-r)*inv(s)%mod;
			dp[i+1]=(dp[i]+a+q*inv(p)%mod*(a+dp[i]-dp[x]+mod)%mod)%mod;
		}
		for(int i=1;i<=Q;i++)
		{
			int L,R;
			scanf("%d%d",&L,&R);
			printf("%lld\n",(dp[R]-dp[L]+mod)%mod);
		}
	}
}
