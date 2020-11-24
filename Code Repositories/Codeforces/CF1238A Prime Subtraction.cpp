#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	ll a,b; 
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&a,&b);
		puts(a-b!=1?"YES":"NO");
	}
}

