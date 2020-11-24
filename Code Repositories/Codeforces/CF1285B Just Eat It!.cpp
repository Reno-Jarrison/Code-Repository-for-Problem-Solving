#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e5+5;
ll a[maxn];
int main()
{
	int t,n,ok;
	cin>>t;
	while(t--)
	{
		cin>>n,ok=1;
		for(int i=1;i<=n;i++) cin>>a[i];
		ll lsum=0,rsum=0;
		for(int i=1;i<n;i++)
		{
			lsum+=a[i];
			if(lsum<=0) ok=0;
		}
		for(int i=n;i>1;i--)
		{
			rsum+=a[i];
			if(rsum<=0) ok=0;
		}
		puts(ok?"YES":"NO");
	}
}