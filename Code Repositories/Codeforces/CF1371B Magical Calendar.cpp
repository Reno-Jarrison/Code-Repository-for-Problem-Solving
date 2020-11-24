#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t,n,r;
	ll ans;
	cin>>t;
	while(t--)
	{
		cin>>n>>r;
		if(n>r) ans=1LL*r*(r+1)/2;
		else ans=1LL*n*(n-1)/2+1;
		cout<<ans<<endl;
	}
}