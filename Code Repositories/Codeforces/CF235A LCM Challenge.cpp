#include<iostream>
#define ll long long
using namespace std;
ll gcd(ll a,ll b)
{ return b?gcd(b,a%b):a; }
int main()
{
	ll n;
	cin>>n;
	if(n==1) cout<<1;
 	else if(n<5) cout<<n*(n-1);
	else if(n%2) cout<<n*(n-1)*(n-2);
	else if(gcd((n-1)*(n-3),n)==1)
		cout<<(n)*(n-1)*(n-3);
	else cout<<(n-1)*(n-2)*(n-3);
}