#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool check(ll x,int cnt)
{
	if(x<cnt) return false; 
	int sum=0;
	while(x) sum+=(x&1),x>>=1;
	return sum<=cnt;
}
int main()
{
	ll n,p;
	cin>>n>>p;
	for(int i=0;i<=40;i++)
	{
		ll tmp=n-1LL*p*i;
		if(tmp<0) break;
		if(check(tmp,i))
		{	printf("%d",i); return 0; }
	}
	printf("-1");
}

