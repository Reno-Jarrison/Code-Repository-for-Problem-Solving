#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll a,b,k,l=0,r=1e8;
		scanf("%lld%lld%lld",&a,&b,&k);
		double p=(2+k+1+sqrt((k+1)*(k+1)+4))/2.0;
		double q=(2-k-1+sqrt((k+1)*(k+1)+4))/2.0;
		if(a<b) swap(a,b);
		while(l<=r)
		{
			ll mid=(l+r)>>1;
			if((ll)floor(p*mid)<a) l=mid+1;
			else r=mid-1;
		}
		puts((ll)floor(p*l)==a&&(ll)floor(q*l)==b?"0":"1");
	}
}