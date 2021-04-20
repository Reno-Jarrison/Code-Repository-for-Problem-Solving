#include<bits/stdc++.h>
#define ll long long
using namespace std;
const double eps=1e-12;
int gcd(int a,int b)
{	return !b?a:gcd(b,a%b); }
int power(int a,int k)
{	
	int ans=1;
	for(int i=1;i<=k;i++) ans*=a;
	return ans;
}
int main()
{
	int a,b,tmp;
	ll ans=0;
	scanf("%d%d",&a,&b),tmp=a;
	vector<pair<int,int>>vec;
	for(int i=2;i*i<=tmp;i++)
		if(tmp%i==0)
		{
			int cnt=0;
			while(tmp%i==0)
				tmp/=i,cnt++;
			vec.emplace_back(i,cnt);
		}
	if(tmp>1) vec.emplace_back(tmp,1);
	int d=vec[0].second,ax=1;
	for(auto x:vec)
		d=gcd(d,x.second);
	for(auto x:vec)
		ax*=power(x.first,x.second/d);
	ll x=ax,t=1;
	while(true)
	{
		if(d*x==t*b) 
		{	ans=x; break; }
		if(1.0*x*ax>1e18) break;
		x*=ax,t++;
	}
	printf("%lld\n",ans);
}