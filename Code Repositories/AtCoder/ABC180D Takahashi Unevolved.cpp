#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	ll x,y,a,b;
	scanf("%lld%lld%lld%lld",&x,&y,&a,&b);
	ll ans=0;
	while(x<=b&&a-1<=b&&x*(a-1)<=b&&x*a<y)
		x*=a,ans++;
	ans+=(y-x-1)/b;
	printf("%lld\n",ans);
}