#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t;
	ll a,b,n,m;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>n>>m;
		int ok=1;
		ll mnv=min(min(a,b),min(n,m));
		a-=mnv,b-=mnv,n-=mnv,m-=mnv;
		if(n&&m) ok=0;
		else
		{
			if(n&&n>(a+b)) ok=0;
			else if(m&&m>min(a,b)) ok=0;
		}
		puts(ok?"Yes":"No");
	}
}