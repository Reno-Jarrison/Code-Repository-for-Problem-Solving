#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll gcd(ll a,ll b)
{	return b?gcd(b,a%b):a; }
ll lcm(ll a,ll b)
{	return a/gcd(a,b)*b; }
int main()
{
	ll x,ans; cin>>x;
	for(ll i=1;i*i<=x;i++) 
		if(x%i==0&&lcm(i,x/i)==x)
			ans=i;
	cout<<ans<<" "<<x/ans;
}
