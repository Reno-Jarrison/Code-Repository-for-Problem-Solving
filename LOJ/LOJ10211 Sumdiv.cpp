#include<bits/stdc++.h>
#define ll long long
#define maxn 1005
#define mod 9901
using namespace std;
ll pf[maxn],pnum[maxn];
ll qpow(ll a,ll b,ll c)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%c;
		a=a*a%c,b>>=1;
	}
	return ans;
}
void exgcd(ll a,ll b,ll& d,ll& x,ll& y)
{
	if(!b) d=a,x=1,y=0;
	else exgcd(b,a%b,d,y,x),y-=a/b*x;
}
ll inv(int a)
{
	ll d,x,y;
	exgcd(a,mod,d,x,y);
	return (x+mod)%mod;
}
int dec(ll a,ll b)  //对a^b分解质因数 
{
	int cnt=0;
	for(int i=2;(ll)i*i<=a;i++)
		if(a%i==0)
		{
			pf[++cnt]=i;
			while(a%i==0) a/=i,pnum[cnt]+=b;
		}
	a>1?pf[++cnt]=a,pnum[cnt]=b:false;
	return cnt;
}
ll fsum(ll a,ll cnt)
{
	ll ans=1;
	for(int i=1;i<=cnt;i++)
	{
		if(pf[i]%mod==1) ans=ans*(pnum[i]+1)%mod;  
		else
		{
			ans*=qpow(pf[i],pnum[i]+1,mod)-1;
			ans=(ans%mod+mod)%mod;
			ans=ans*inv(pf[i]-1)%mod;
		} 
	}
	return ans;
}
int main()
{
	ll a,b,cnt;
	scanf("%lld%lld",&a,&b);
	cnt=dec(a,b);
	printf("%lld",fsum(a,cnt));
}