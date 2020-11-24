#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	int t,n,g,b;
	cin>>t;
	while(t--)
	{
		cin>>n>>g>>b;
		int m=(n+1)>>1;
		ll p=m/g,r=m%g,rest=n-m;
		if(!r) p--,r=g;
		rest-=min(rest,p*b);
		cout<<p*(g+b)+r+rest<<endl;
	}
}