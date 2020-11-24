#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	ll x,y,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld%lld",&x,&y,&k);
		printf("%lld\n",(k*y+k-1)/(x-1)+((k*y+k-1)%(x-1)>0)+k);
	}
}