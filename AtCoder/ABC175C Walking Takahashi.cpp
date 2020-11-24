#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll x,k,d,q,r;
	scanf("%lld%lld%lld",&x,&k,&d);
	x=abs(x),q=x/d,r=x%d;
	if(k<=q) printf("%lld\n",x-d*k);
	else printf("%lld\n",(k-q)&1?d-r:r);
}