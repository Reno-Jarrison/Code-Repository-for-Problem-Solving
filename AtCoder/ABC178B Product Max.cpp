#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll a,b,c,d;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	printf("%lld\n",max(max(a*d,b*c),max(a*c,b*d)));
}
