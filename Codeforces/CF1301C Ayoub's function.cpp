#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll sum(ll x)
{	return x*(x+1)/2; }
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n,m0,m1,ans;
		cin>>n>>m1,m0=n-m1;
		ll len=m0/(m1+1),r=m0%(m1+1);
		ans=sum(n)-(m1-r+1)*sum(len)-r*sum(len+1);
		cout<<ans<<endl;
	}
}