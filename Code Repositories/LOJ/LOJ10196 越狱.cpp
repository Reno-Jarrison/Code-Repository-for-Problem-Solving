#include<bits/stdc++.h>
#define ll long long
#define mod 100003
using namespace std;
ll qpow(ll a,ll b,ll p)
{
	ll ans=1;
	while(b)
	{
		if(b&1) (ans*=a)%=p; 
		(a*=a)%=p,b>>=1;
	} 
	return ans%p;
} 
int main()
{
	ll m,n;
	cin>>m>>n;
	cout<<(qpow(m,n-1,mod)-qpow(m-1,n-1,mod)+mod)%mod*m%mod;
}