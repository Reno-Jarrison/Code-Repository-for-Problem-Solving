#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
int t,f[1000005]={0,1};
ll qpow(ll a,ll b,ll m)
{
	ll ans=1;
	while(b)
	{
		if(b&1) ans=ans*a%m;
		a=a*a%m,b>>=1;
	}
	return ans;
}
int main()
{
	cin>>t;
	ll a,b,n,sqn,m;
	while(t--)
	{
		cin>>a>>b>>n,sqn=n*n;
		if(n==1||a==0)
		{	cout<<0<<endl; continue; }
		for(int i=2;i<=sqn;i++)
		{
			f[i]=(f[i-1]+f[i-2])%n;
			if(f[i]==1&&f[i-1]==0)
			{	m=i-1; break; }
		}
		cout<<f[qpow(a%m,b,m)]<<endl;
	}
}
