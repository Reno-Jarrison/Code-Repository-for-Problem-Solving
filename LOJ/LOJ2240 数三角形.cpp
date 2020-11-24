#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll C3(ll n)
{	return n*(n-1)*(n-2)/6; }
int gcd(int a,int b)
{	return !b?a:gcd(b,a%b); }
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	ll ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans+=1LL*(n-i+1)*(m-j+1)*(gcd(i,j)-1);
	ans=ans*2+C3(n+1)*(m+1)+C3(m+1)*(n+1);
	printf("%lld\n",C3((n+1)*(m+1))-ans);
}