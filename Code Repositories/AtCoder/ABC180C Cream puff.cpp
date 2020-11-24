#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll n;
	scanf("%lld",&n);
	set<ll>st;
	for(int i=1;1LL*i*i<=n;i++) if(n%i==0) 
		st.insert(i),st.insert(n/i);
	for(ll x:st)
		printf("%lld\n",x);
}