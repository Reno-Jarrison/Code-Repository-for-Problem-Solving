#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#define ll long long
using namespace std;
ll gcd(ll a,ll b)
{	return !b?a:gcd(b,a%b); }
int main()
{
	ll n;
	while(scanf("%lld",&n)&&n)
	{
		ll tmp=n>0?n:-n;
		if(tmp<=1) { puts("1"); continue; }
		vector<ll>v;
		for(int i=2;1LL*i*i<=tmp;i++)
			if(tmp%i==0)
			{
				int cnt=0;
				while(tmp%i==0)
					cnt++,tmp/=i;
				v.push_back(cnt);
			}
		if(tmp>1) v.push_back(1);
		ll ans=v[0];
		for(ll i=1;i<v.size();i++) ans=gcd(ans,v[i]);
		if(n<0) while(ans%2==0) ans>>=1;
		printf("%lld\n",ans);
	}
}