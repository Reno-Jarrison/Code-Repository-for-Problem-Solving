#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=3e5+5,mod=998244353;
struct node
{
	int l,r;
}p[maxn];
ll fac[maxn],invf[maxn];
bool cmp(const node& a,const node& b)
{	return a.l<b.l; }
bool operator <(const node& a,const node& b)
{	return a.r>b.r; }
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
void solve(int n)
{
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%mod;
	invf[n]=qpow(fac[n],mod-2);
	for(int i=n-1;~i;i--)
		invf[i]=invf[i+1]*(i+1)%mod;
}
ll C(ll n,ll m)
{
	if(m>n) return 0;
	return fac[n]*invf[m]%mod*invf[n-m]%mod;
}
int main()
{
	int n,k;
	solve(3e5);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&p[i].l,&p[i].r);
	sort(p+1,p+n+1,cmp);
	priority_queue<node>hp;
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		int cur=p[i].l;
		while(!hp.empty()&&hp.top().r<cur) hp.pop();
		ans=(ans+C(hp.size(),k-1))%mod;
		hp.push(p[i]);
	}
	printf("%lld\n",ans);
}