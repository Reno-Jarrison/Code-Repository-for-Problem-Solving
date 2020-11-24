#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t,a,b;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		ll x=abs(a-b),tmp=0;
		while((tmp)*(tmp+1)/2<x) tmp++;
		ll rest=tmp*(tmp+1)/2-x;
		while(rest&1) rest+=++tmp;
		printf("%lld\n",tmp);
	}	
}