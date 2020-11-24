#include<bits/stdc++.h>
#define ll long long
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
	ll a,b,m;
	cin>>a>>b>>m;
	cout<<qpow(a,b,m); 
}