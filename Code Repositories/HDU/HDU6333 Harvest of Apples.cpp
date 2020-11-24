#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5,mod=1e9+7;
struct query
{	int l,r,b,id; }q[maxn];
bool operator <(const query& x,const query& y)
{	return x.b==y.b?(x.b?(x.r<y.r):(x.r>y.r)):x.b<y.b; }
ll fac[maxn]={1},inv[maxn],ans[maxn],tmp;
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
void init(int n)
{
	for(int i=1;i<=n;i++) 
		fac[i]=fac[i-1]*i%mod;
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n-1;~i;i--)
		inv[i]=inv[i+1]*(i+1)%mod;
}
ll C(int n,int m)
{	return fac[n]*inv[m]%mod*inv[n-m]%mod; }
ll decl(ll cur,int l,int r)
{	return (cur+C(l-1,r))*inv[2]%mod; }
ll incl(ll cur,int l,int r)
{	return (cur*2-C(l,r)+mod)%mod; }
ll decr(ll cur,int l,int r)
{	return (cur-C(l,r)+mod)%mod; }
ll incr(ll cur,int l,int r)
{	return (cur+C(l,r+1))%mod; }
int main()
{
	init(1e5);
	int n,block=sqrt(1e5),lpt,rpt;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&q[i].l,&q[i].r);
		q[i].id=i,q[i].b=q[i].l/block;
	}
	sort(q+1,q+n+1);
	lpt=rpt=1,tmp=2;
	for(int i=1;i<=n;i++)
	{
		while(lpt<q[i].l) tmp=incl(tmp,lpt++,rpt);
		while(rpt>q[i].r) tmp=decr(tmp,lpt,rpt--);
		while(rpt<q[i].r) tmp=incr(tmp,lpt,rpt++);
		while(lpt>q[i].l) tmp=decl(tmp,lpt--,rpt);
		ans[q[i].id]=tmp;
	}
	for(int i=1;i<=n;i++)
		printf("%lld\n",ans[i]);
}